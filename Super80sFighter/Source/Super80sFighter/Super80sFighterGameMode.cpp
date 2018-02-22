// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterGameMode.h"
#include "ThugClass.h"
#include "UObject/ConstructorHelpers.h"

#define GAMEPAD_BUILD

void ASuper80sFighterGameMode::BeginPlay()
{
	Super::BeginPlay();

	p1_controller = UGameplayStatics::GetPlayerController(this, 0);
	Player1 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	p2_controller = UGameplayStatics::CreatePlayer(this, 1);
	Player2 = Cast<ASuper80sFighterCharacter>(UGameplayStatics::GetPlayerPawn(this, 1));

	//variables required for spawning a character as a different type
	UWorld* const world = GetWorld();
	FActorSpawnParameters spawn_parameters = FActorSpawnParameters();
	FVector pos;
	FRotator rot = FRotator(0, -90, 0);
	ASuper80sFighterCharacter* temp;
	//change player 1 (or possibly not if hes default class)
	switch (p1_type)
	{
	case ECharacterEnum::CLASS_DEFAULT:
		//do nothing, characters already spawn as base classes
		break;
	case ECharacterEnum::CLASS_THUG:
		pos = Player1->GetTransform().GetLocation();
		spawn_parameters.bDeferConstruction = true;
		p1_controller->UnPossess();
		Player1->destroy();
		temp = world->SpawnActor<AThugClass>(ThugClass, pos, rot, spawn_parameters);
		UGameplayStatics::FinishSpawningActor(temp, temp->GetTransform());
		Player1 = temp;
		p1_controller->Possess(Player1);
		break;
	case ECharacterEnum::CLASS_TOBY:
		UE_LOG(LogTemp, Fatal, TEXT("FATAL ERROR: TOBY NOT YET IMPLEMENTED"));
		break;
	default:
		break;
	}
	//change player 2 (once again, possibly not if your match is boring and you have the default fighter)
	switch (p2_type)
	{
	case ECharacterEnum::CLASS_DEFAULT:
		//do nothing, this is default pawn
		break;
	case ECharacterEnum::CLASS_THUG:
		pos = Player2->GetTransform().GetLocation();
		spawn_parameters.bDeferConstruction = true;
		p2_controller->UnPossess();
		Player2->destroy();
		temp = world->SpawnActor<AThugClass>(ThugClass, pos, rot, spawn_parameters);
		UGameplayStatics::FinishSpawningActor(temp, temp->GetTransform());
		Player2 = temp;
		p2_controller->Possess(Player2);
		break;
	case ECharacterEnum::CLASS_TOBY:
		UE_LOG(LogTemp, Fatal, TEXT("FATAL ERROR: TOBY NOT YET IMPLEMENTED"));
		break;
	default:
		break;
	}

	Player1->SetOtherPlayer(Player2);
	Player2->SetOtherPlayer(Player1);

	first_time = true;
	rounds_remaining = num_rounds;

}

void ASuper80sFighterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (on_death_pause)
	{
		death_timer -= DeltaTime;
		if (death_timer <= 0)
			on_death_pause = false;
	}
	if (Player1->GetCurrentHealth() <= 0)
	{
		Player1->SetDead(true);
		Player2->SetDead(false);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3.0f;
			first_time = false;
		}
		if (!on_death_pause)
			endRound(false);
	}
	else if (Player2->GetCurrentHealth() <= 0)
	{
		Player1->SetDead(false);
		Player2->SetDead(true);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3.0f;
			first_time = false;
		}
		if (!on_death_pause)
			endRound(true);
	}
	else if (round_draw)
	{
		Player2->SetDead(true);
		Player1->SetDead(true);
		if (first_time)
		{
			on_death_pause = true;
			death_timer = 3;
			first_time = false;
		}
		if (!on_death_pause)
			internal_draw();
	}
	else
	{
		Player2->SetDead(false);
		Player1->SetDead(false);
	}
}

ASuper80sFighterGameMode::ASuper80sFighterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnBPClass(TEXT("Blueprint'/Game/SideScrollerCPP/Blueprints/Character/ThugClassBlueprint.ThugClassBlueprint'"));
	PrimaryActorTick.bCanEverTick = true;
	if (PlayerPawnBPClass.Object != NULL)
	{
		ThugClass = (UClass*)PlayerPawnBPClass.Object->GeneratedClass;
	}
	num_rounds = 1;
	rounds_remaining = num_rounds;
}


#pragma region Controls 
void ASuper80sFighterGameMode::OverrideKeyInput(FKey inputKey, FString InputName)
{
	const UInputSettings* InputSettings = GetDefault<UInputSettings>();
	for (int i = InputSettings->ActionMappings.Num() - 1; i >= 0; i--)
	{
		if (((UInputSettings*)InputSettings)->ActionMappings[i].ActionName.ToString() == InputName)
			((UInputSettings*)InputSettings)->ActionMappings.RemoveAt(i);
	}

	FInputActionKeyMapping actionmapping(FName(*InputName), inputKey, false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);
	((UInputSettings*)InputSettings)->SaveKeyMappings();
}
void ASuper80sFighterGameMode::OverrideAxisInput(FKey inputKey, FString InputName, float axisScaler, bool shouldWeErase)
{
	const UInputSettings* InputSettings = GetDefault<UInputSettings>();

#ifdef GAMEPAD_BUILD
	if (shouldWeErase)
		for (int i = InputSettings->AxisMappings.Num() - 1; i >= 0; i--)
		{
			if (((UInputSettings*)InputSettings)->AxisMappings[i].AxisName.ToString() == InputName && !((UInputSettings*)InputSettings)->AxisMappings[i].Key.ToString().Contains("Gamepad"))
				((UInputSettings*)InputSettings)->AxisMappings.RemoveAt(i);
		}
#else
	if (shouldWeErase)
		for (int i = InputSettings->AxisMappings.Num() - 1; i >= 0; i--)
		{
			if (((UInputSettings*)InputSettings)->AxisMappings[i].AxisName.ToString() == InputName)
				((UInputSettings*)InputSettings)->AxisMappings.RemoveAt(i);
		}

#endif // GAMEPAD_BUILD




	FInputAxisKeyMapping axismapping = FInputAxisKeyMapping(FName(*InputName), inputKey, axisScaler);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);

	((UInputSettings*)InputSettings)->SaveKeyMappings();
}
FString ASuper80sFighterGameMode::ConvertKeyToString(FKey inKey)
{
	return inKey.ToString();
}
void ASuper80sFighterGameMode::ResetInputs()
{

#pragma region Comments for having gamepad names
	//	// Ensure that the GamepadKeyNames match those in InputCoreTypes.cpp
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftAnalogX("Gamepad_LeftX");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftAnalogY("Gamepad_LeftY");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightAnalogX("Gamepad_RightX");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightAnalogY("Gamepad_RightY");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftTriggerAnalog("Gamepad_LeftTriggerAxis");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightTriggerAnalog("Gamepad_RightTriggerAxis");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftThumb("Gamepad_LeftThumbstick");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightThumb("Gamepad_RightThumbstick");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::SpecialLeft("Gamepad_Special_Left");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::SpecialLeft_X("Gamepad_Special_Left_X");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::SpecialLeft_Y("Gamepad_Special_Left_Y");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::SpecialRight("Gamepad_Special_Right");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonBottom("Gamepad_FaceButton_Bottom");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonRight("Gamepad_FaceButton_Right");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonLeft("Gamepad_FaceButton_Left");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::FaceButtonTop("Gamepad_FaceButton_Top");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftShoulder("Gamepad_LeftShoulder");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightShoulder("Gamepad_RightShoulder");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftTriggerThreshold("Gamepad_LeftTrigger");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightTriggerThreshold("Gamepad_RightTrigger");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::DPadUp("Gamepad_DPad_Up");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::DPadDown("Gamepad_DPad_Down");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::DPadRight("Gamepad_DPad_Right");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::DPadLeft("Gamepad_DPad_Left");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickUp("Gamepad_LeftStick_Up");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickDown("Gamepad_LeftStick_Down");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickRight("Gamepad_LeftStick_Right");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::LeftStickLeft("Gamepad_LeftStick_Left");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightStickUp("Gamepad_RightStick_Up");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightStickDown("Gamepad_RightStick_Down");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightStickRight("Gamepad_RightStick_Right");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::RightStickLeft("Gamepad_RightStick_Left");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton1("MotionController_Left_FaceButton1");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton2("MotionController_Left_FaceButton2");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton3("MotionController_Left_FaceButton3");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton4("MotionController_Left_FaceButton4");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton5("MotionController_Left_FaceButton5");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton6("MotionController_Left_FaceButton6");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton7("MotionController_Left_FaceButton7");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_FaceButton8("MotionController_Left_FaceButton8");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Shoulder("MotionController_Left_Shoulder");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Trigger("MotionController_Left_Trigger");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip1("MotionController_Left_Grip1");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip2("MotionController_Left_Grip2");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick("MotionController_Left_Thumbstick");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Up("MotionController_Left_Thumbstick_Up");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Down("MotionController_Left_Thumbstick_Down");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Left("MotionController_Left_Thumbstick_Left");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Right("MotionController_Left_Thumbstick_Right");
	//
	//	//		Right Controller
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton1("MotionController_Right_FaceButton1");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton2("MotionController_Right_FaceButton2");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton3("MotionController_Right_FaceButton3");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton4("MotionController_Right_FaceButton4");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton5("MotionController_Right_FaceButton5");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton6("MotionController_Right_FaceButton6");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton7("MotionController_Right_FaceButton7");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_FaceButton8("MotionController_Right_FaceButton8");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Shoulder("MotionController_Right_Shoulder");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Trigger("MotionController_Right_Trigger");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip1("MotionController_Right_Grip1");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip2("MotionController_Right_Grip2");
	//
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick("MotionController_Right_Thumbstick");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Up("MotionController_Right_Thumbstick_Up");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Down("MotionController_Right_Thumbstick_Down");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Left("MotionController_Right_Thumbstick_Left");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Right("MotionController_Right_Thumbstick_Right");
	//
	//	//   Motion Controller Axes
	//	//		Left Controller
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_X("MotionController_Left_Thumbstick_X");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Thumbstick_Y("MotionController_Left_Thumbstick_Y");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_TriggerAxis("MotionController_Left_TriggerAxis");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip1Axis("MotionController_Left_Grip1Axis");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Left_Grip2Axis("MotionController_Left_Grip2Axis");
	//
	//	//		Right Controller
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_X("MotionController_Right_Thumbstick_X");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Thumbstick_Y("MotionController_Right_Thumbstick_Y");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_TriggerAxis("MotionController_Right_TriggerAxis");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip1Axis("MotionController_Right_Grip1Axis");
	//	const FGamepadKeyNames::Type FGamepadKeyNames::MotionController_Right_Grip2Axis("MotionController_Right_Grip2Axis");
#pragma endregion

	const UInputSettings* InputSettings = GetDefault<UInputSettings>();


	for (int i = InputSettings->ActionMappings.Num() - 1; i >= 0; i--)
	{
		((UInputSettings*)InputSettings)->ActionMappings.RemoveAt(i);
	}
	for (int i = InputSettings->AxisMappings.Num() - 1; i >= 0; i--)
	{
		((UInputSettings*)InputSettings)->AxisMappings.RemoveAt(i);
	}
#pragma region Jumping
	FInputActionKeyMapping actionmapping(FName("HighJump"), FKey(EKeys::Up), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("HighJump"), FKey(EKeys::X), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("ShortHop"), FKey(EKeys::SpaceBar), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Jump"), FKey(EKeys::W), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Jump"), FKey("Gamepad_RightStick_Up"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Jump"), FKey("Gamepad_LeftStick_Up"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);
#pragma endregion


	actionmapping = FInputActionKeyMapping(FName("Pause"), FKey(EKeys::I), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Pause"), FKey("Gamepad_Special_Right"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

#pragma region Attacks

	actionmapping = FInputActionKeyMapping(FName("Attack1"), FKey(EKeys::J), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Attack1"), FKey("Gamepad_FaceButton_Left"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);


	actionmapping = FInputActionKeyMapping(FName("Attack2"), FKey(EKeys::K), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Attack2"), FKey("Gamepad_FaceButton_Bottom"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);


	actionmapping = FInputActionKeyMapping(FName("Attack3"), FKey(EKeys::L), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Attack3"), FKey("Gamepad_FaceButton_Right"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);


	actionmapping = FInputActionKeyMapping(FName("Attack4"), FKey(EKeys::Semicolon), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Attack4"), FKey("Gamepad_FaceButton_Top"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);
#pragma endregion


	actionmapping = FInputActionKeyMapping(FName("Crouch"), FKey(EKeys::S), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Crouch"), FKey("Gamepad_RightStick_Down"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("Crouch"), FKey("Gamepad_LeftStick_Down"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressRight"), FKey(EKeys::D), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressRight"), FKey("Gamepad_RightStick_Right"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressRight"), FKey("Gamepad_LeftStick_Right"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressLeft"), FKey(EKeys::A), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressLeft"), FKey("Gamepad_RightStick_Left"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);

	actionmapping = FInputActionKeyMapping(FName("PressLeft"), FKey("Gamepad_LeftStick_Left"), false, false, false, false);
	((UInputSettings*)InputSettings)->AddActionMapping(actionmapping);












	FInputAxisKeyMapping axismapping(FName("MoveRight"), FKey(EKeys::D), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);

	axismapping = FInputAxisKeyMapping(FName("MoveLeft"), FKey(EKeys::A), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);

	axismapping = FInputAxisKeyMapping(FName("MoveRight"), FKey("Gamepad_LeftStick_Right"), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);
	axismapping = FInputAxisKeyMapping(FName("MoveRight"), FKey("Gamepad_RightStick_Right"), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);

	axismapping = FInputAxisKeyMapping(FName("MoveLeft"), FKey("Gamepad_LeftStick_Left"), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);
	axismapping = FInputAxisKeyMapping(FName("MoveLeft"), FKey("Gamepad_RightStick_Left"), 1.0f);
	((UInputSettings*)InputSettings)->AddAxisMapping(axismapping);







	((UInputSettings*)InputSettings)->SaveKeyMappings();
}
#pragma endregion


void ASuper80sFighterGameMode::draw()
{
	round_draw = true;

}

void ASuper80sFighterGameMode::endRound(bool p1_win)
{
	rounds_remaining--;
	if (p1_win)
	{
		Player1_round_wins++;
	}
	else
	{
		Player2_round_wins++;

	}
	if (rounds_remaining == 0)
		endGame();

	Player1->comboCounter = 0;
	Player2->comboCounter = 0;

	Player1->SetActorLocation(Player1->startLocation);
	Player1->ResetHealth();
	Player1->ResetStamina();
	Player2->SetActorLocation(Player2->startLocation);
	Player2->ResetHealth();
	Player2->ResetStamina();
	first_time = true;
	on_death_pause = false;

	UE_LOG(LogTemp, Warning, TEXT("%d"), rounds_remaining);
}

void ASuper80sFighterGameMode::internal_draw()
{
	Player1->SetActorLocation(Player1->startLocation);
	Player1->ResetHealth();
	Player1->ResetStamina();
	Player2->SetActorLocation(Player2->startLocation);
	Player2->ResetHealth();
	Player2->ResetStamina();
	first_time = true;
	on_death_pause = false;
	round_draw = false;
}

void ASuper80sFighterGameMode::endGame()
{
	paused = true;
}
