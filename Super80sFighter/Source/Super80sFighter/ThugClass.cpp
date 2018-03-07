#pragma region Initialize
//Fill out your copyright notice in the Description page of Project Settings.
#include "ThugClass.h"
#include "../Core/Public/Misc/FileHelper.h"
#include "../CoreUObject/Public/UObject/UObjectIterator.h"
#include "../Engine/Classes/Engine/BlockingVolume.h"


//The default constructor.
AThugClass::AThugClass()
{
	//Set up the Thug's functionality.
	SetUpThug();
}

void AThugClass::initialize_move_data()
{
	for (TObjectIterator<ABlockingVolume> itr; itr; ++itr)
	{
		ABlockingVolume * idontknowwhatimdoing = *itr;
		if (idontknowwhatimdoing->GetName().Equals(FString(TEXT("Left_Boundary"))))
			left_boundary = FVector(idontknowwhatimdoing->GetActorLocation());
		else if (idontknowwhatimdoing->GetName().Equals(FString(TEXT("Right_Boundary"))))
			left_boundary = FVector(idontknowwhatimdoing->GetActorLocation());
	}

	FString file_path = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/ThugClassAIData.bin"));
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* file_handle = PlatformFile.OpenRead(*file_path);
	int file_size = PlatformFile.FileSize(*file_path);
	UE_LOG(LogTemp, Warning, TEXT("f_size 1: %d"), file_size);
	file_size = file_size / 12;
	UE_LOG(LogTemp, Warning, TEXT("f_size 2: %d"), file_size);

	for (int i = 0; i < file_size; ++i)
	{
		int _index;
		float _damage;
		float _stamina_cost;
		file_handle->Read((uint8*)(&_index), 4);
		file_handle->Read((uint8*)(&_damage), 4);
		file_handle->Read((uint8*)(&_stamina_cost), 4);
		bool already_in_move_list = false;
		for (int j = 0; j < my_player_data.Move_Data.Num(); ++j)
		{
			if (CommandList[_index].functionToCall == CommandList[my_player_data.Move_Data[j].command_list_index].functionToCall)
			{
				UE_LOG(LogTemp, Warning, TEXT("temp function was already in the list, this was the attack with the damage value of %f"), _damage);
				already_in_move_list = true;
			}
		}
		if (!already_in_move_list)
		{
			UE_LOG(LogTemp, Warning, TEXT("temp function was not in the list, this was the attack with the damage value of %f"), _damage);

			Move_Data temp;
			temp.command_list_index = _index;
			temp.past_attempt = 0;
			temp.past_success = 0;
			temp.combo_potential = 1; //this is temporary until i understand more of the combo system and how that works
									  //NOTE - these final three values will be recieved from a save file that will be created for each character... for now they are pretty much nothing
			temp.damage = _damage;
			temp.stamina_cost = 0;
			temp.timeframe_cost = 0;
			//-------------------------------------------------------------------------------------------------------------------------------------------------
			my_player_data.Move_Data.Push(temp);
		}
	}
	//close the file handle
	delete file_handle;

	//check to see if we actually got our function pointers correctly
	for (int i = 0; i < CommandList.Num(); ++i)
	{
		for (int j = 0; j < my_player_data.Move_Data.Num(); ++j)
		{
			if (CommandList[i].functionToCall == CommandList[my_player_data.Move_Data[j].command_list_index].functionToCall)
			{
				UE_LOG(LogTemp, Warning, TEXT("function at command list index %d matched with function at move_data index %d"), i, j);
			}
		}
	}
}

void AThugClass::saveHitboxData(float stamina_cost)
{
	if (attack_saved_bool_32 & (1 << last_called_attack_index))
	{
		//save data here
		FString file_path = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/ThugClassAIData.bin"));
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		IFileHandle* file_handle = PlatformFile.OpenWrite(*file_path, true);
		if (file_handle)
		{
			UE_LOG(LogTemp, Warning, TEXT("entered the file handle"));
			//allocate memory to save, see details below for what is being saved
			uint8* byte_array = reinterpret_cast<uint8*>(FMemory::Malloc(4 + 4 + 4));
			//copy 4 bytes for the attack's function pointer index
			memcpy(byte_array, &last_called_attack_index, 4);
			//copy 4 bytes for the attack's damage
			memcpy(byte_array + 4, &tempHitbox->damage, 4);
			//copy 4 bytes for the stamina cost
			memcpy(byte_array + 8, &stamina_cost, 4);
			//write out the data
			file_handle->Write(byte_array, 12);
			//close the handle
			delete file_handle;
			FMemory::Free(byte_array);
		}
		attack_saved_bool_32 -= (1 << last_called_attack_index);
	}
}

void AThugClass::deleteOldSaveData(IPlatformFile & PlatformFile)
{
	FString GENERALKENOBI = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/ThugClassAIData.bin"));
	if (PlatformFile.DeleteFile(*GENERALKENOBI))
	{
		UE_LOG(LogTemp, Warning, TEXT("Previous test file Deleted"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no test file found to delete"));
	}
}

//Set up the Thug's functionality.
void AThugClass::SetUpThug()
{
	//Add the default inputs for every Thug.
	inputsToUse.Add(MOVEFORWARD);
	inputsToUse.Add(MOVEBACKWARD);
	inputsToUse.Add(HOP);
	inputsToUse.Add(JUMP);
	inputsToUse.Add(CROUCH);
	inputsToUse.Add(PUNCH);
	inputsToUse.Add(KICK);

	//Determine the moves the Thug will have available to them.
	DetermineMoveSet(inputsToUse, difficultyLevel);
}

//Determine the moves the Thug will have available to them.
void AThugClass::DetermineMoveSet(TArray<short>& _inputsToUse, short _difficultyLevel)
{
	//Get the random moveset for the Thug to use.
	movesetNumber = rand() % TOTALMOVESETS;

	//Determine the stage the player is on.
	switch (_difficultyLevel)
	{
		//Easy difficulty.
	case 0:
		_inputsToUse.Add(SPECIAL1);
		break;

		//Medium difficulty.
	case 1:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		break;

		//Hard difficulty.
	case 2:
		_inputsToUse.Add(SPECIAL1);
		_inputsToUse.Add(SPECIAL2);
		_inputsToUse.Add(SPECIAL3);
		_inputsToUse.Add(SPECIAL4);
		break;

		//No difficulty.
	default:
		break;
	}
}
#pragma endregion

#pragma region AIMoves
//Choose the next move for the Thug to perform.
void AThugClass::ChooseNextMove()
{
	//Get the random move for the Thug to use.
	int randomMove;
	if (!save_hitbox_data)
		randomMove = rand() % TOTALMOVES;
	else
		randomMove = save_counter;

	save_counter = (save_counter + 1) % TOTALMOVES;

	//Set the available moves to the Thug.
	switch (randomMove)
	{
	case 0:
		if (movesetNumber == 0)
		{
			isMove0 = true;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = true;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = true;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 1:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = true;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = true;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = true;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 2:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = true;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = true;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = true;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 3:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = true;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = true;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = true;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 4:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = true;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = true;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = true;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 5:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = true;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = true;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = true;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 6:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = true;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = true;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = true;
			isMove25 = false;
			isMove26 = false;
		}
		break;

	case 7:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = true;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = true;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = true;
			isMove26 = false;
		}
		break;

	case 8:
		if (movesetNumber == 0)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = true;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 1)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = true;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = false;
		}

		else if (movesetNumber == 2)
		{
			isMove0 = false;
			isMove1 = false;
			isMove2 = false;
			isMove3 = false;
			isMove4 = false;
			isMove5 = false;
			isMove6 = false;
			isMove7 = false;
			isMove8 = false;
			isMove9 = false;
			isMove10 = false;
			isMove11 = false;
			isMove12 = false;
			isMove13 = false;
			isMove14 = false;
			isMove15 = false;
			isMove16 = false;
			isMove17 = false;
			isMove18 = false;
			isMove19 = false;
			isMove20 = false;
			isMove21 = false;
			isMove22 = false;
			isMove23 = false;
			isMove24 = false;
			isMove25 = false;
			isMove26 = true;
		}
		break;

	default:
		break;
	}
}
#pragma endregion

#pragma region Update
//Increment the timer, called every frame.
void AThugClass::Tick(float _deltaTime)
{
	//Use the parent's timer to perform the tick.
	Super::Tick(_deltaTime);

	//Choose the next move for the Thug to perform.
	ChooseNextMove();
}
#pragma endregion




