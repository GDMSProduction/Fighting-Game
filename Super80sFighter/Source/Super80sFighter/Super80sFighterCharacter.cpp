//Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#include "Super80sFighterCharacter.h"
#include "ThugClass.h"
#include "../Core/Public/Misc/FileHelper.h"
#include "../CoreUObject/Public/UObject/UObjectIterator.h"
#include "../Engine/Classes/Engine/BlockingVolume.h"

AFighterParent::AFighterParent()
{
	//I love asian qt3.14s
	//Set size for collision capsule.
	GetCapsuleComponent()->InitCapsuleSize(42.00f, 96.00f);

	//Disable overlap events on the characters capsule component.
	GetCapsuleComponent()->bGenerateOverlapEvents = false;

	//Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//Create a camera boom attached to the root (capsule).
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.00f;
	CameraBoom->SocketOffset = FVector(0.00f, 0.00f, 75.00f);
	CameraBoom->RelativeRotation = FRotator(0.00f, 180.00f, 0.00f);

	//Create a camera and attach to boom.
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
															  // Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.00f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.00f;
	GetCharacterMovement()->GroundFriction = 3.00f;
	GetCharacterMovement()->MaxWalkSpeed = 600.00f;
	GetCharacterMovement()->MaxFlySpeed = 600.00f;

	TotalStamina = 100.00f;
	CurrentStamina = TotalStamina;

	TotalHealth = 100.00f;
	CurrentHealth = TotalHealth;

	CustomHighJumpVelocity = 1000.00f;
	CustomShortJumpVelocity = 700.00f;
	JumpThreshold = 0.10f;
	AttackThreshold = 0.20f;
	BlockThreshold = 0.05f;

	holdThreshold = 0.13;

	//Framecount divided by 60.00 for how many frames of leniency to give in between attacks before buffer.
	samePressThreshold = 1.0 / 60.00;

#pragma region Adding in commands for attacks
	TArray<ButtonSet> tempCommand;
	ButtonSet buttonSet;
	ButtonInput button1;

	button1.button = PUNCH;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);
	tempCommand.Push(buttonSet);
	AddCommand<AFighterParent>(CommandList, tempCommand, &AFighterParent::Attack0);


	button1.button = KICK;
	button1.wasHeld = false;
	buttonSet.Clear();
	buttonSet.inputs.Add(button1);
	tempCommand.Push(buttonSet);
	AddCommand<AFighterParent>(CommandList, tempCommand, &AFighterParent::Attack1);

	while (tempCommand.Num() > 0)
		tempCommand.RemoveAt(0);

	buttonSet.Clear();
	button1.button = HEAVY;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);

	buttonSet.Clear();
	button1.button = RIGHT;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);

	buttonSet.Clear();
	button1.button = DOWN;
	buttonSet.inputs.Add(button1);
	tempCommand.Add(buttonSet);

	AddCommand<AFighterParent>(CommandList, tempCommand, &AFighterParent::Attack3);

	while (tempCommand.Num() > 0)
		tempCommand.RemoveAt(0);

	buttonSet.Clear();
	button1.button = PUNCH;
	button1.wasHeld = true;
	buttonSet.inputs.Add(button1);
	button1.button = KICK;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);

	tempCommand.Add(buttonSet);
	AddCommand<AFighterParent>(CommandList, tempCommand, &AFighterParent::Attack2);

	while (tempCommand.Num() > 0)
		tempCommand.RemoveAt(0);

	buttonSet.Clear();
	button1.button = HEAVY;
	button1.wasHeld = false;
	buttonSet.inputs.Add(button1);
	button1.button = SPECIAL;
	buttonSet.inputs.Add(button1);

	tempCommand.Add(buttonSet);
	AddCommand<AFighterParent>(CommandList, tempCommand, &AFighterParent::AttackTaunt);

#pragma endregion

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++) 


}
#pragma region Initialization
void AFighterParent::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	int id = -1;

#pragma region Get Id
	if (GetPlayerController() != nullptr)
		id = GetPlayerController()->GetLocalPlayer()->GetControllerId();//My intellisense says its bad but it compiles and works. Fuck you VS
#pragma endregion
	if (id == 0)
	{
		PlayerInputComponent->BindAction("HighJump_P1", IE_Pressed, this, &AFighterParent::PressHighJump);
		PlayerInputComponent->BindAction("HighJump_P1", IE_Released, this, &AFighterParent::ReleaseHighJump);
		PlayerInputComponent->BindAction("ShortHop_P1", IE_Pressed, this, &AFighterParent::PressShortHop);
		PlayerInputComponent->BindAction("ShortHop_P1", IE_Released, this, &AFighterParent::ReleaseShortHop);
		PlayerInputComponent->BindAction("Jump_P1", IE_Pressed, this, &AFighterParent::PressNormalJump);
		PlayerInputComponent->BindAction("Jump_P1", IE_Released, this, &AFighterParent::ReleaseNormalJump);
		PlayerInputComponent->BindAction("PressRight_P1", IE_Pressed, this, &AFighterParent::PressRight);
		PlayerInputComponent->BindAction("PressRight_P1", IE_Released, this, &AFighterParent::ReleaseRight);
		PlayerInputComponent->BindAction("PressLeft_P1", IE_Pressed, this, &AFighterParent::PressLeft);
		PlayerInputComponent->BindAction("PressLeft_P1", IE_Released, this, &AFighterParent::ReleaseLeft);
		PlayerInputComponent->BindAxis("MoveRight_P1", this, &AFighterParent::MoveRight);
		PlayerInputComponent->BindAxis("MoveLeft_P1", this, &AFighterParent::MoveLeft);
		PlayerInputComponent->BindAction("Attack1_P1", IE_Pressed, this, &AFighterParent::PressPunch);
		PlayerInputComponent->BindAction("Attack2_P1", IE_Pressed, this, &AFighterParent::PressKick);
		PlayerInputComponent->BindAction("Attack3_P1", IE_Pressed, this, &AFighterParent::PressHeavy);
		PlayerInputComponent->BindAction("Attack4_P1", IE_Pressed, this, &AFighterParent::PressSpecial);
		PlayerInputComponent->BindAction("Attack1_P1", IE_Released, this, &AFighterParent::ReleasePunch);
		PlayerInputComponent->BindAction("Attack2_P1", IE_Released, this, &AFighterParent::ReleaseKick);
		PlayerInputComponent->BindAction("Attack3_P1", IE_Released, this, &AFighterParent::ReleaseHeavy);
		PlayerInputComponent->BindAction("Attack4_P1", IE_Released, this, &AFighterParent::ReleaseSpecial);
		PlayerInputComponent->BindAction("Crouch_P1", IE_Pressed, this, &AFighterParent::StartCrouch);
		PlayerInputComponent->BindAction("Crouch_P1", IE_Released, this, &AFighterParent::StopCrouch);

		PlayerInputComponent->BindAction("PunchKick_P1", IE_Pressed, this, &AFighterParent::PressPunchAndKick);
		PlayerInputComponent->BindAction("PunchKick_P1", IE_Released, this, &AFighterParent::ReleasePunchAndKick);

		PlayerInputComponent->BindAction("KickSpecial_P1", IE_Pressed, this, &AFighterParent::PressKickAndSpecial);
		PlayerInputComponent->BindAction("KickSpecial_P1", IE_Released, this, &AFighterParent::ReleaseKickAndSpecial);

	}

	else if (id == 1)
	{
		PlayerInputComponent->BindAction("HighJump_P2", IE_Pressed, this, &AFighterParent::PressHighJump);
		PlayerInputComponent->BindAction("HighJump_P2", IE_Released, this, &AFighterParent::ReleaseHighJump);
		PlayerInputComponent->BindAction("ShortHop_P2", IE_Pressed, this, &AFighterParent::PressShortHop);
		PlayerInputComponent->BindAction("ShortHop_P2", IE_Released, this, &AFighterParent::ReleaseShortHop);
		PlayerInputComponent->BindAction("Jump_P2", IE_Pressed, this, &AFighterParent::PressNormalJump);
		PlayerInputComponent->BindAction("Jump_P2", IE_Released, this, &AFighterParent::ReleaseNormalJump);
		PlayerInputComponent->BindAction("PressRight_P2", IE_Pressed, this, &AFighterParent::PressRight);
		PlayerInputComponent->BindAction("PressRight_P2", IE_Released, this, &AFighterParent::ReleaseRight);
		PlayerInputComponent->BindAction("PressLeft_P2", IE_Pressed, this, &AFighterParent::PressLeft);
		PlayerInputComponent->BindAction("PressLeft_P2", IE_Released, this, &AFighterParent::ReleaseLeft);
		PlayerInputComponent->BindAxis("MoveRight_P2", this, &AFighterParent::MoveRight);
		PlayerInputComponent->BindAxis("MoveLeft_P2", this, &AFighterParent::MoveLeft);
		PlayerInputComponent->BindAction("Attack1_P2", IE_Pressed, this, &AFighterParent::PressPunch);
		PlayerInputComponent->BindAction("Attack2_P2", IE_Pressed, this, &AFighterParent::PressKick);
		PlayerInputComponent->BindAction("Attack3_P2", IE_Pressed, this, &AFighterParent::PressHeavy);
		PlayerInputComponent->BindAction("Attack4_P2", IE_Pressed, this, &AFighterParent::PressSpecial);
		PlayerInputComponent->BindAction("Attack1_P2", IE_Released, this, &AFighterParent::ReleasePunch);
		PlayerInputComponent->BindAction("Attack2_P2", IE_Released, this, &AFighterParent::ReleaseKick);
		PlayerInputComponent->BindAction("Attack3_P2", IE_Released, this, &AFighterParent::ReleaseHeavy);
		PlayerInputComponent->BindAction("Attack4_P2", IE_Released, this, &AFighterParent::ReleaseSpecial);
		PlayerInputComponent->BindAction("Crouch_P2", IE_Pressed, this, &AFighterParent::StartCrouch);
		PlayerInputComponent->BindAction("Crouch_P2", IE_Released, this, &AFighterParent::StopCrouch);

		PlayerInputComponent->BindAction("PunchKick_P2", IE_Pressed, this, &AFighterParent::PressPunchAndKick);
		PlayerInputComponent->BindAction("PunchKick_P2", IE_Released, this, &AFighterParent::ReleasePunchAndKick);

		PlayerInputComponent->BindAction("KickSpecial_P2", IE_Pressed, this, &AFighterParent::PressKickAndSpecial);
		PlayerInputComponent->BindAction("KickSpecial_P2", IE_Released, this, &AFighterParent::ReleaseKickAndSpecial);
	}

	//spawn a hitbox on the player that can be hit and attacked
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX, FVector(0, 0, -80), FVector(.5f, .5f, 1.5f), 0, false);
	spawnHitbox(EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX, FVector(0, 0, -60), FVector(.35f, .35f, 1.25f), 0, false);

	//add onHit to capsule component
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AFighterParent::onHit);

	//set startLocation
	startLocation = GetTransform().GetLocation();
	//set starting max stam stams
	stamina_tier = 3;
	health_tier = 3;
	regen_stamina = true;
	CurrentMaxStamina = TotalStamina;

	//testin shit
	//add 16 for the TArray of Commands
	//total_memory_cost += 16;
	//for (int i = 0; i < CommandList.Num(); ++i)
	//{
	//	//start with memory at 32, 16 for the function pointer, 16 for the TArray of InputsForCommand
	//	int command_memory = 32;
	//	for (int j = 0; j < CommandList[i].InputsForCommand.Num(); ++j)
	//	{
	//		//add 16 to command_memory for each TArray of inputs
	//		command_memory += 16;
	//		for (int k = 0; k < CommandList[i].InputsForCommand[j].inputs.Num(); ++k)
	//		{
	//			command_memory += sizeof(CommandList[i].InputsForCommand[j].inputs[k]);
	//		}
	//	}
	//	total_memory_cost += command_memory;
	//}

	//If this is a save run, create a save file directory.
	if (save_hitbox_data)
	{
		FString hellothere = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data"));
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

		if (!PlatformFile.DirectoryExists(*hellothere))
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find directory, attempting to create one"));
			PlatformFile.CreateDirectory(*hellothere);

			if (!PlatformFile.DirectoryExists(*hellothere))
			{
				UE_LOG(LogTemp, Warning, TEXT("ERROR: COULD NOT CREATE DIRECTORY FOR AI DATA"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Successfully created the directory"));
			}
		}
		deleteOldSaveData(PlatformFile);
	}
	else
		initialize_move_data();

}
APlayerController * AFighterParent::GetPlayerController()
{
	APlayerController* ret = Cast<APlayerController>(Controller);
	return ret;
}
void AFighterParent::SetOtherPlayer(AFighterParent * OtherPlayer)
{
	EnemyPlayer = OtherPlayer;
}
#pragma endregion
#pragma region Health and Stamina
float AFighterParent::GetTotalStamina()
{
	return TotalStamina;
}
float AFighterParent::GetCurrentStamina()
{
	return CurrentStamina;
}
void AFighterParent::UpdateCurrentStamina(float Stamina)
{
	CurrentStamina = CurrentStamina + Stamina;
}
void AFighterParent::UpdateCurrentHealth(float Health)
{
	CurrentHealth = CurrentHealth + Health;
}
float AFighterParent::GetTotalHealth()
{
	return TotalHealth;
}
float AFighterParent::GetCurrentHealth()
{
	return CurrentHealth;
}
void AFighterParent::SetStaminaRegen(bool tf)
{
	regen_stamina = tf;
}
#pragma endregion
#pragma region Death and Destruction
void AFighterParent::destroy()
{
	for (int i = 0; i < hitboxes.Num(); ++i)
		hitboxes[i]->Destroy();
	Destroy();
}
bool AFighterParent::GetDead()
{
	return isDead;
}
void AFighterParent::SetDead(bool willBeDead)
{
	this->isDead = willBeDead;
}
#pragma endregion
#pragma region Hitboxes
void AFighterParent::takeDamage(float damage)
{
	//If the player is ready to block a standing attack.
	//if (playerState == backingUp && standingUp)
	//{
		//damage = Block(damage);
		//playerScore.damageBlockedAverage += damage;
	//}

	//If the player is ready to block a crouching attack.
	//if (playerState == backingUp && crouching)
	//{
	//	damage = CrouchBlock(damage);
	//	playerScore.damageBlockedAverage += damage;
	//}

	UpdateCurrentHealth(-damage);

	TakeDamageBlueprintEvent();

	//Possibly update current stamina to reflect new max stamina.
	if (TotalHealth * 0.25f > CurrentHealth && health_tier == 1)
	{
		health_tier--;
		stamina_tier--;
	}

	else if (TotalHealth * 0.50f > CurrentHealth && health_tier == 2)
	{
		health_tier--;
		stamina_tier--;
	}

	else if (TotalHealth * 0.75f > CurrentHealth && health_tier == 3)
	{
		health_tier--;
		stamina_tier--;
	}

	switch (stamina_tier)
	{
	case 0:
		CurrentMaxStamina = TotalStamina * 0.25f;
		break;
	case 1:
		CurrentMaxStamina = TotalStamina * 0.5f;
		break;
	case 2:
		CurrentMaxStamina = TotalStamina * 0.75f;
		break;
	case 3:
		CurrentMaxStamina = TotalStamina;
		break;
	default:
		break;
	}

	if (CurrentStamina > CurrentMaxStamina)
	{
		CurrentStamina = CurrentMaxStamina;
	}

	//if (attack == thisAttack)
	//{
		EnemyPlayer->playerScore.numHits++;
	//}

	EnemyPlayer->ComboCounter();
}
AHitbox* AFighterParent::spawnHitbox(EHITBOX_TYPE type, FVector offset, FVector dimensions, float damage, float stamina_cost, bool visible)
{
	UpdateCurrentStamina(-stamina_cost);
	FVector tempVec;
	tempVec = GetTransform().GetLocation();
	FRotator rot(GetTransform().GetRotation());
	FActorSpawnParameters sp = FActorSpawnParameters();
	sp.bDeferConstruction = true;

	tempHitbox = GetWorld()->SpawnActor<AHitbox>(AHitbox::StaticClass(), tempVec, rot, sp);
	tempHitbox->GetTransform().SetLocation(tempVec);

	//reenable if we don't want all hitboxes to move with the player
	//if (type == EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX || type == EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX)
	//{
	FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, true);
	tempHitbox->AttachToComponent(RootComponent, rules);
	//}
	tempHitbox->SetHitboxProperties(type, offset, dimensions, damage, visible);

	hitboxes.Add(tempHitbox);

	//save hitbox data (if this is a save run and its a strike hitbox)
	if (save_hitbox_data && (tempHitbox->hitboxType == EHITBOX_TYPE::VE_HITBOX_STRIKE || tempHitbox->hitboxType == EHITBOX_TYPE::VE_HITBOX_THROW))
	{
		saveHitboxData(stamina_cost);
	}
	return tempHitbox;
}
void AFighterParent::StopBlocking()
{
	isBlocking = false;
}
float AFighterParent::Block(float _damage)
{
	//Begin blocking.
	isBlocking = true;

	//Decrease the amount of damage the player will take.
	_damage *= 0.50f;

	//Increment the total number of attacks blocked.
	++playerScore.numAttacksBlocked;

	//Set (and reset upon finishing) the blocking timer.
	GetWorld()->GetTimerManager().SetTimer(BlockTimer, this, &AFighterParent::StopBlocking, BlockThreshold);

	//Return the modified (lower) damage amount.
	return (_damage);
}
float AFighterParent::CrouchBlock(float _damage)
{
	//Begin blocking.
	isBlocking = true;

	//Decrease the amount of damage the player will take.
	_damage *= 0.50f;

	//Increment the total number of attacks blocked.
	++playerScore.numAttacksBlocked;

	//Set (and reset upon finishing) the blocking timer.
	GetWorld()->GetTimerManager().SetTimer(BlockTimer, this, &AFighterParent::StopBlocking, BlockThreshold);

	//Return the modified (lower) damage amount.
	return (_damage);
}
#pragma endregion

#pragma region AI
void AFighterParent::decide()
{
	decide_movement();
}
void AFighterParent::initialize_move_data()
{
	for (TObjectIterator<ABlockingVolume> itr; itr; ++itr)
	{
		ABlockingVolume * idontknowwhatimdoing = *itr;
		if (idontknowwhatimdoing->GetName().Equals(FString(TEXT("Left_Boundary"))))
			left_boundary = idontknowwhatimdoing->GetTransform().GetLocation();
		else if (idontknowwhatimdoing->GetName().Equals(FString(TEXT("Right_Boundary"))))
			left_boundary = idontknowwhatimdoing->GetTransform().GetLocation();
	}


	FString file_path = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/FighterParentAIData.bin"));
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
void AFighterParent::notify_incoming_attack(int attack_index)
{
	attack_incoming = true;
	UE_LOG(LogTemp, Warning, TEXT("Attack incoming"));
}
void AFighterParent::notify_attack_ending()
{
	attack_incoming = false;
	UE_LOG(LogTemp, Warning, TEXT("Attack ending"));
}
void AFighterParent::decide_movement()
{
	prev_distance = curr_distance;
	curr_distance = distance(GetTransform().GetLocation(), EnemyPlayer->GetTransform().GetLocation());
	float left_boundary_distance = distance(GetTransform().GetLocation(), left_boundary);
	float right_boundary_distance = distance(GetTransform().GetLocation(), right_boundary);

	//UE_LOG(LogTemp, Warning, TEXT("Enemy not in attack range, deciding movement"));
	//ill use this variable to decide which direction to go
	FVector desired_movement = FVector::ZeroVector;
	bool try_jumping = false;
	//multiply by the scale and then -1 because unreal is wierd... this way, forward will be a positive number, and back will be negative
	int direction = GetTransform().GetScale3D().X * -1;
	//if we have the health advantage, push the enemy. otherwise, back off a little
	//desired_movement.Y += ((CurrentHealth - EnemyPlayer->CurrentHealth) * -.05f * GetTransform().GetScale3D().X);
	//if the enemy is coming towards us, we should probably not move forward
	if (EnemyPlayer->GetTransform().GetLocation() != enemy_previous_location && curr_distance < prev_distance)
		desired_movement.Y += (-1 * direction);
	//enemy projectiles incoming
	//desired_movement.Y += 2.0; flat value to determine how forwardy they'll go, keep it high 
	//if an attack is coming and you're in range, move back a bit
	if (attack_incoming)
		desired_movement.Y += (-2 * direction);
	//if being cornered, try jumping over the other player
	if ((left_boundary_distance < 300 && GetTransform().GetLocation().Y > EnemyPlayer->GetTransform().GetLocation().Y) || (right_boundary_distance < 300 && GetTransform().GetLocation().Y < EnemyPlayer->GetTransform().GetLocation().Y))
	{
		desired_movement.Y += (10 * direction);
		try_jumping = true;
	}
	//always try to approach the enemy , other factors will cut this down a bit or even possibly reverse direction
	desired_movement.Y += (1 * direction);
	ControlInputVector += desired_movement;
	enemy_previous_location = EnemyPlayer->GetTransform().GetLocation();
	if (try_jumping)
		PressHighJump();
}
void AFighterParent::deleteOldSaveData(IPlatformFile& PlatformFile)
{
	FString GENERALKENOBI = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/FighterParentAIData.bin"));
	if (PlatformFile.DeleteFile(*GENERALKENOBI))
	{
		UE_LOG(LogTemp, Warning, TEXT("Previous test file Deleted"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no test file found to delete"));
	}
}
void AFighterParent::saveHitboxData(float stamina_cost)
{
	if (attack_saved_bool_32 & (1 << last_called_attack_index))
	{
		//save data here
		FString file_path = FString(TEXT("C:/Users/disca/Documents/GitHub/Fighting-Game/Super80sFighter/Content/SideScrollerCPP/AI Data/FighterParentAIData.bin"));
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
void AFighterParent::set_last_called_attack_index(int _index)
{
	last_called_attack_index = _index;
}
float AFighterParent::distance(FVector a, FVector b)
{	
	return fast_sqrt((((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)) + ((a.Z - b.Z) * (a.Z - b.Z))));
}
float AFighterParent::fast_sqrt(float num)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = num * 0.5F;
	y = num;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = 1 / y;

	return y;
}
#pragma endregion

#pragma region Character Reset
void AFighterParent::ResetHealth()
{
	CurrentHealth = TotalHealth;
	health_tier = 3;
}
void AFighterParent::ResetStamina()
{
	CurrentStamina = TotalStamina;
	stamina_tier = 3;
}
#pragma endregion
#pragma region Character Inputs
void AFighterParent::SuperAbility()
{
	UpdateCurrentStamina((-0.25f) * TotalStamina);
}
void AFighterParent::MoveRight(float Value)
{
	// add movement in that direction
	if (grounded && !isDead && !what_is_my_purpose)
		ControlInputVector += (FVector(0, -1.f, 0) * Value);
}
void AFighterParent::MoveLeft(float Val)
{
	MoveRight(-Val);
}
void AFighterParent::PressRight()
{
	
	AddInput<AFighterParent>(RIGHT, true, FApp::GetCurrentTime());
}
void AFighterParent::PressLeft()
{
	AddInput<AFighterParent>(LEFT, true, FApp::GetCurrentTime());
}
void AFighterParent::ReleaseRight()
{
	AddInput<AFighterParent>(RIGHT, false, FApp::GetCurrentTime());
}
void AFighterParent::ReleaseLeft()
{
	AddInput<AFighterParent>(LEFT, false, FApp::GetCurrentTime());
}
void AFighterParent::PressPunch()
{
	AddInput<AFighterParent>(INPUT_TYPE::PUNCH, true, FApp::GetCurrentTime());
}
void AFighterParent::PressKick()
{

	AddInput<AFighterParent>(INPUT_TYPE::KICK, true, FApp::GetCurrentTime());
}
void AFighterParent::PressHeavy()
{

	AddInput<AFighterParent>(INPUT_TYPE::HEAVY, true, FApp::GetCurrentTime());
}
void AFighterParent::PressSpecial()
{

	AddInput<AFighterParent>(INPUT_TYPE::SPECIAL, true, FApp::GetCurrentTime());
}
void AFighterParent::PressPunchAndKick()
{
	PressPunch();
	PressKick();
}
void AFighterParent::PressKickAndSpecial()
{
	PressKick();
	PressSpecial();
}
void AFighterParent::ReleasePunch()
{
	AddInput<AFighterParent>(INPUT_TYPE::PUNCH, false, FApp::GetCurrentTime());
}
void AFighterParent::ReleaseKick()
{

	AddInput<AFighterParent>(INPUT_TYPE::KICK, false, FApp::GetCurrentTime());
}
void AFighterParent::ReleaseHeavy()
{

	AddInput<AFighterParent>(INPUT_TYPE::HEAVY, false, FApp::GetCurrentTime());
}
void AFighterParent::ReleaseSpecial()
{

	AddInput<AFighterParent>(INPUT_TYPE::SPECIAL, false, FApp::GetCurrentTime());
}
void AFighterParent::ReleasePunchAndKick()
{
	ReleasePunch();
	ReleaseKick();
}
void AFighterParent::ReleaseKickAndSpecial()
{
	ReleaseKick();
	ReleaseSpecial();
}
void AFighterParent::TauntStaminaRegen()
{
	if (stamina_tier < 3)
	{
		stamina_tier++;
		switch (stamina_tier)
		{
		case 0:
			CurrentMaxStamina = TotalStamina * .25f;
			break;
		case 1:
			CurrentMaxStamina = TotalStamina * .5f;
			break;
		case 2:
			CurrentMaxStamina = TotalStamina * .75f;
			break;
		case 3:
			CurrentMaxStamina = TotalStamina;
			break;
		default:
			break;
		}
	}
}
void AFighterParent::StartCrouch()
{
	isCrouching = true;
	AddInput<AFighterParent>(DOWN, true, FApp::GetCurrentTime());
}
void AFighterParent::StopCrouch()
{
	isCrouching = false;
	AddInput<AFighterParent>(DOWN, false, FApp::GetCurrentTime());
}
void AFighterParent::CheckCommand()

{
	if (isDead)
		return;

	TArray<ButtonSet> tempCommandBuffer;


#pragma region Create the temporary CommandBuffer
	TArray<ButtonBufferInput> bufferCopy;
	for (int cur = 0; cur < buttonBuffer.Num(); cur++) bufferCopy.Add(buttonBuffer[cur]);//Inline explicit copy


	ButtonSet currentButtonSet;

	ButtonBufferInput previousTest = bufferCopy.Last();

	int a = bufferCopy.Num();

	while (bufferCopy.Num() > 0) {
		ButtonBufferInput test = bufferCopy.Last();
		double testint = test.timeOfInput - previousTest.timeOfInput;
		if (previousTest.timeOfInput - test.timeOfInput > samePressThreshold) {//If the next button was pressed at a different time than the others
			tempCommandBuffer.Add(currentButtonSet);
			currentButtonSet.Clear();
		}

		if (!test.isPress)
		{
			//If its a release
			bool found = false;
			for (int i = bufferCopy.Num() - 2; i >= 0; i--)//starting from the next button press, going down
			{
				if (bufferCopy[i].isPress && bufferCopy[i].Buttons == test.Buttons) {//If its a press and its the same input type
					found = true;
					bool held = (bufferCopy[i].timeOfInput - test.timeOfInput >= holdThreshold);

					ButtonInput tempButton;
					tempButton.button = test.Buttons;
					tempButton.wasHeld = held;
					currentButtonSet.inputs.Push(tempButton);

					bufferCopy.RemoveAt(i);
					break;
				}

			}

			if (!found)
			{
				ButtonInput tempButton;
				tempButton.button = test.Buttons;
				tempButton.wasHeld = true;
				currentButtonSet.inputs.Push(tempButton);
			}

			bufferCopy.RemoveAt(bufferCopy.Num() - 1);
		}
		else //If its a press
		{
			ButtonInput tempButton;
			tempButton.button = test.Buttons;
			tempButton.wasHeld = false;
			currentButtonSet.inputs.Push(tempButton);

			bufferCopy.RemoveAt(bufferCopy.Num() - 1);
		}

		previousTest = test;
	}
	tempCommandBuffer.Push(currentButtonSet);
#pragma endregion


	if (tempCommandBuffer.Num() == 0)
		return;


	TArray<Command<AFighterParent>> CommandCopy;

	for (int cur = 0; cur < CommandList.Num(); cur++) CommandCopy.Add(CommandList[cur]);//Create a copy of the commandlist
																						//For each item in the AlreadyCalledCommands:
																						//Remove it from the copy of commandList
	for (int cur = 0; cur < AlreadyCalledCommands.Num(); ++cur) {
		QueStopAttacking();
		CommandCopy.Remove(AlreadyCalledCommands[cur]);

	};


#pragma region Set "Forward" and "Backward"
	INPUT_TYPE forward;
	INPUT_TYPE backward;
	if (EnemyPlayer->GetTransform().GetLocation().Y > GetTransform().GetLocation().Y) {
		forward = INPUT_TYPE::LEFT;
		backward = INPUT_TYPE::RIGHT;
	}
	else
	{
		forward = INPUT_TYPE::RIGHT;
		backward = INPUT_TYPE::LEFT;
	}
	for (int i = 0; i < CommandCopy.Num(); i++)
	{
		for (int j = 0; j < CommandCopy[i].InputsForCommand.Num(); j++)
		{
			for (int k = 0; k < CommandCopy[i].InputsForCommand[j].inputs.Num(); k++)
			{
				if (CommandCopy[i].InputsForCommand[j].inputs[k].button == RIGHT)
					CommandCopy[i].InputsForCommand[j].inputs[k].button = forward;
				else if (CommandCopy[i].InputsForCommand[j].inputs[k].button == LEFT)
					CommandCopy[i].InputsForCommand[j].inputs[k].button = backward;
			}
		}
	}
#pragma endregion


	for (int currentCommand = 0; currentCommand < CommandCopy.Num(); currentCommand++)
	{
		for (int i = 0; i < tempCommandBuffer.Num() && i + CommandCopy[currentCommand].InputsForCommand.Num() <= tempCommandBuffer.Num(); i++)
		{
			if (tempCommandBuffer[i] == CommandCopy[currentCommand].InputsForCommand[0]) {
				bool same = true;
				for (int j = i; j < CommandCopy[currentCommand].InputsForCommand.Num() + i; j++)
				{
					if (tempCommandBuffer[j] != CommandCopy[currentCommand].InputsForCommand[j - i]) {
						same = false;
						break;
					}
				}
				if (same) {
					(this->*CommandCopy[currentCommand].functionToCall)();
					AlreadyCalledCommands.Add(CommandCopy[currentCommand]);
				}
			}
		}
	}
};
void AFighterParent::ClearCommands()
{
	while (buttonBuffer.Num() != 0)
		buttonBuffer.RemoveAt(0);
	while (AlreadyCalledCommands.Num() != 0)
		AlreadyCalledCommands.RemoveAt(0);

	QueStopAttacking();
}
void AFighterParent::Attack0()
{
	QueStopAttacking();
	isAttacking0 = true;

	if (save_hitbox_data || EnemyPlayer->what_is_my_purpose)
	{
		for (int i = 0; i < CommandList.Num(); ++i)
		{
			if (CommandList[i].functionToCall == &AFighterParent::Attack0)
			{
				set_last_called_attack_index(i);
				break;
			}
		}
	}
}
void AFighterParent::Attack1()
{
	QueStopAttacking();
	isAttacking1 = true;

	if (save_hitbox_data || EnemyPlayer->what_is_my_purpose)
	{
		for (int i = 0; i < CommandList.Num(); ++i)
		{
			if (CommandList[i].functionToCall == &AFighterParent::Attack1)
			{
				set_last_called_attack_index(i);
				break;
			}
		}
	}
}
void AFighterParent::Attack2()
{
	QueStopAttacking();
	isAttacking2 = true;

	if (save_hitbox_data || EnemyPlayer->what_is_my_purpose)
	{
		for (int i = 0; i < CommandList.Num(); ++i)
		{
			if (CommandList[i].functionToCall == &AFighterParent::Attack2)
			{
				set_last_called_attack_index(i);
				break;
			}
		}
	}
}
void AFighterParent::Attack3()
{
	QueStopAttacking();
	isAttacking3 = true;

	if (save_hitbox_data || EnemyPlayer->what_is_my_purpose)
	{
		for (int i = 0; i < CommandList.Num(); ++i)
		{
			if (CommandList[i].functionToCall == &AFighterParent::Attack3)
			{
				set_last_called_attack_index(i);
				break;
			}
		}
	}
}
void AFighterParent::AttackTaunt()
{
	QueStopAttacking();
	isAttackingTaunt = true;
	++playerScore.numTaunts;

	if (save_hitbox_data || EnemyPlayer->what_is_my_purpose)
	{
		for (int i = 0; i < CommandList.Num(); ++i)
		{
			if (CommandList[i].functionToCall == &AFighterParent::AttackTaunt)
			{
				set_last_called_attack_index(i);
				break;
			}
		}
	}
}
void AFighterParent::SetLastPressedKey(FKey inKey)
{
	LastPressedKey = inKey;
}
FKey AFighterParent::GetLastPressedKey()
{
	return LastPressedKey;
}
void AFighterParent::QueStopAttacking() {
	isAttacking0 = false;
	isAttacking1 = false;
	isAttacking2 = false;
	isAttacking3 = false;
	isAttackingTaunt = false;
}

void AFighterParent::ComboCounter()
{
	bool proMode = false;

	//If "Pro-Mode" is on (each attack must be within four frames for an input-combo).
	if (proMode)
	{
		if (lastHit + 2.00f <= GetWorld()->GetTimerManager().GetTimerElapsed(AttackTimer))
		{
			++comboCounter;
		}

		else
		{
			comboCounter = 0;
		}
	}

	//If "Pro-Mode" is off (each attack must be within eight frames for an input-combo).
	else
	{
		if (lastHit + 0.000000000001f <= GetWorld()->GetTimerManager().GetTimerElapsed(AttackTimer))
		{
			++comboCounter;
		}

		else
		{
			comboCounter = 0;
		}
	}

	if (comboCounter >= 2 && comboCounter < 4)
	{

	}

	else if (comboCounter >= 4)
	{

	}

	lastHit = GetWorld()->GetTimerManager().GetTimerElapsed(AttackTimer);
}
#pragma endregion
#pragma region Overloaded Unreal
void AFighterParent::onHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	lock_grounded = false;
	if (OtherActor == EnemyPlayer)
	{
		//fix issue with jumping on top of other players
		FVector my_location = GetTransform().GetLocation();
		FVector enemy_location = EnemyPlayer->GetTransform().GetLocation();
		if (my_location.Z > enemy_location.Z)
		{
			if (my_location.Y >= enemy_location.Y)
				non_grounded_forces += FVector(0, 50, 0);
			else
				non_grounded_forces += FVector(0, -50, 0);
			lock_grounded = true;
		}
	}
}
void AFighterParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (what_is_my_purpose)
		decide();

	//switch (initialSelector)
	//{
	//case 0:
	//	if (initialCounter > 0)
	//	{
	//		--initialCounter;
	//	}

	//	else
	//	{
	//		initialCounter = 25;
	//	}

	//	break;

	//case 1:
	//	if (initial2Counter > 0)
	//	{
	//		--initial2Counter;
	//	}

	//	else
	//	{
	//		initial2Counter = 25;
	//	}

	//	break;

	//case 2:
	//	if (initial3Counter > 0)
	//	{
	//		--initial3Counter;
	//	}

	//	else
	//	{
	//		initial3Counter = 25;
	//	}

	//	break;
	//}

	//implementing my physics
	if (!lock_grounded)
	{
		grounded = GetCharacterMovement()->IsMovingOnGround();
	}

	//The functionality for creating effects on land.
	if (!grounded)
	{
		landedEffect = true;
	}

	if (grounded && landedEffect)
	{
		LandEffectBlueprintEvent();
		landedEffect = false;
	}

	if (grounded)
	{
		non_grounded_forces = FVector(0, 0, 0);
		jumpEffect = true;
	}

	else
		grounded_forces = FVector(0, 0, 0);
	//Currently using .05f so really small forces are ignored, change to 0 if you want to include very small forces.
	if (FVector::DistSquared(FVector::ZeroVector, non_grounded_forces) > .05f)
	{
		ControlInputVector += non_grounded_forces * DeltaTime;
		non_grounded_forces -= non_grounded_forces * DeltaTime;
	}

	if (FVector::DistSquared(FVector::ZeroVector, grounded_forces) > .05f)
	{
		ControlInputVector += grounded_forces * DeltaTime;
		grounded_forces -= grounded_forces * DeltaTime;
	}

	if (FVector::DistSquared(FVector::ZeroVector, absolute_forces) > .05f)
	{
		ControlInputVector += absolute_forces * DeltaTime;
		grounded_forces -= absolute_forces * DeltaTime;
	}

	//Flipping the character on grounded.
	if (grounded) 
	{
		if (EnemyPlayer->GetTransform().GetLocation().Y > GetTransform().GetLocation().Y)
		{
			FlipCharacter(false);
		}

		else
		{
			FlipCharacter(true);
		}
	}

	else
	{
		FlipCharacter(IsFacingRight);
	}

	//stamina stuff
	if (CurrentStamina < CurrentMaxStamina && regen_stamina)
	{
		CurrentStamina += (DeltaTime * 5);
	}
}
#pragma endregion
#pragma region Jump functions
void AFighterParent::PressShortHop()
{
	GetCharacterMovement()->JumpZVelocity = CustomShortJumpVelocity;
	PressJump();

	if (jumpEffect)
	{
		JumpEffectBlueprintEvent();
		jumpEffect = false;
	}
}
void AFighterParent::ReleaseShortHop()
{
	ReleaseJump();
}
void AFighterParent::PressHighJump()
{
	GetCharacterMovement()->JumpZVelocity = CustomHighJumpVelocity;
	PressJump();

	if (jumpEffect)
	{
		HighJumpEffectBlueprintEvent();
		jumpEffect = false;
	}
}
void AFighterParent::ReleaseHighJump()
{
	ReleaseJump();
}
void AFighterParent::PressNormalJump()
{
	GetWorld()->GetTimerManager().SetTimer(JumpTimer, this, &AFighterParent::JumpReachesThreshold, JumpThreshold);
	HasJumpReachedThreshold = false;
}
void AFighterParent::ReleaseNormalJump() {

	if (HasJumpReachedThreshold)
	{
		GetCharacterMovement()->JumpZVelocity = CustomHighJumpVelocity;
	}
	else
	{
		GetCharacterMovement()->JumpZVelocity = CustomShortJumpVelocity;
	}

	PressJump();
}
void AFighterParent::PressJump()
{
	if (!isDead)
	{
		ACharacter::Jump();
		if (jumpEffect)
		{
			JumpEffectBlueprintEvent();
			jumpEffect = false;
		}
	}

	isHoldingJump = true;
	PressUp<AFighterParent>();
}
void AFighterParent::ReleaseJump()
{
	ACharacter::StopJumping();
	ReleaseUp<AFighterParent>();
	isHoldingJump = false;
	ReleaseUp<AFighterParent>();
}
void AFighterParent::JumpReachesThreshold()
{
	HasJumpReachedThreshold = true;

	ReleaseNormalJump();
}
#pragma endregion
#pragma region Miscellaneous Character Functions
void AFighterParent::FlipCharacter()
{
	FlipCharacter(!IsFacingRight);

}
void AFighterParent::FlipCharacter(bool forceFaceRight)
{
	if (forceFaceRight)//If we're forcing them to face right, face them right
	{
		//Set the transform scale x component to 1
		FVector trans = GetTransform().GetScale3D();
		trans.X = 1.0f;
		SetActorScale3D(trans);

	}
	else//If we're forcing them to face left, face them left
	{
		//Set the transform scale x component to -1
		FVector trans = GetTransform().GetScale3D();
		trans.X = -1.0f;
		SetActorScale3D(trans);

	}

	IsFacingRight = forceFaceRight;
}
void AFighterParent::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}
void AFighterParent::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}
#pragma endregion