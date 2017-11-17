// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Super80sFighterCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASuper80sFighterCharacter::ASuper80sFighterCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASuper80sFighterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASuper80sFighterCharacter::MoveRight);
	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &ASuper80sFighterCharacter::Attack0);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &ASuper80sFighterCharacter::Attack1);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &ASuper80sFighterCharacter::Attack2);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &ASuper80sFighterCharacter::Attack3);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASuper80sFighterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASuper80sFighterCharacter::TouchStopped);
}

void ASuper80sFighterCharacter::MoveRight(float Value)
{
	// add movement in that direction

	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}
void ASuper80sFighterCharacter::Attack0()
{
	StopAttacking();
	isAttacking0 = true;
	UE_LOG(LogTemp, Warning, TEXT("Attacking with first attack"));


}

void ASuper80sFighterCharacter::Attack1()
{
	StopAttacking();
	isAttacking1 = true;
	UE_LOG(LogTemp, Warning, TEXT("Attacking with second attack"));
	

}
void ASuper80sFighterCharacter::Attack2()
{
	StopAttacking();
	isAttacking2 = true;
	UE_LOG(LogTemp, Warning, TEXT("Attacking with third attack"));


}
void ASuper80sFighterCharacter::Attack3()
{
	StopAttacking();
	isAttacking3 = true;
	UE_LOG(LogTemp, Warning, TEXT("Attacking with fourth attack"));


}


void ASuper80sFighterCharacter::StopAttacking() {
	isAttacking0 = false;
	isAttacking1 = false;
	isAttacking2 = false;
	isAttacking3 = false;



}
void ASuper80sFighterCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ASuper80sFighterCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

