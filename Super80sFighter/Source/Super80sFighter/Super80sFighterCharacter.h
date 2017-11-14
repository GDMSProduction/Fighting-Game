// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Super80sFighterCharacter.generated.h"

UCLASS(config=Game)
class ASuper80sFighterCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

private:
	/**Player Total Stamina*/
	UPROPERTY(EditAnywhere, Category = "Stats")
		float TotalStamina;

	/**Player Current Stamina*/
	UPROPERTY(EditAnywhere, Category = "Stats")
		float CurrentStamina;

	/**Player Total Health*/
	UPROPERTY(EditAnywhere, Category = "Stats")
		float TotalHealth;

	/**Player Current Health*/
	UPROPERTY(EditAnywhere, Category = "Stats")
		float CurrentHealth;

public:
	ASuper80sFighterCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/**Accessor function for Total Stamina*/
	UFUNCTION(BlueprintPure, Category = "Stats")
		float GetTotalStamina();

	/**Accessor function for Current Stamina*/
	UFUNCTION(BlueprintPure, Category = "Stats")
		float GetCurrentStamina();

	/**Updates the Players Current Stamina
	* @param Stamina Amount to change Stamina by(Posivive or Negative).
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void UpdateCurrentStamina(float Stamina);

	/**Accessor function for Total Health*/
	UFUNCTION(BlueprintPure, Category = "Stats")
		float GetTotalHealth();

	/**Accessor function for Current Health*/
	UFUNCTION(BlueprintPure, Category = "Stats")
		float GetCurrentHealth();

	/**Updates the Players Current Stamina
	* @param Health Amount to change Stamina by(Posivive or Negative).
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void UpdateCurrentHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void TakingDamage();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SuperAbility();

	virtual void Tick(float DeltaTime) override;
};
