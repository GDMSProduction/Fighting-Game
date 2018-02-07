// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hitbox.generated.h"


//enum for hitbox types
UENUM(BlueprintType)
enum class EHITBOX_TYPE : uint8
{
	VE_HITBOX_STRIKE			UMETA(DisplayName="Strike"),		//hitbox of a strike attack
	VE_HITBOX_PROJECTILE		UMETA(DisplayName="Projectile"),	//hitbox of a projectile attack
	VE_HITBOX_PROXIMITY			UMETA(DisplayName = "Proximity"),	//hitbox that protrudes from an attack to determine whether the player should block it
	VE_HITBOX_THROW				UMETA(DisplayName="Throw"),			//hitbox that shows the area that the grab attack is affecting
	VE_HITBOX_GET_PAINBOX		UMETA(DisplayName="P_Hitbox"),		//the area of the player that can be hit
	VE_HITBOX_GET_THROWBOX		UMETA(DisplayName="P_Throwbox")		//the grab area of a player
};



UCLASS()
class SUPER80SFIGHTER_API AHitbox : public AActor
{
	GENERATED_BODY()


public:	

	//-------------------------------------Primary Hitbox Attributes------------------------------------------------

	//the type of hitbox this is
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Details")
	EHITBOX_TYPE hitboxType;

	//position of the hitbox relative to the character's center
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Details")
	FVector hitboxPosition;

	//whether or not to display the hitbox to the user (off by default)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Details")
	bool showHitbox;

	//color of the hitbox
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hitbox Details")
	FColor color;

	//a mesh to show the hitbox
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hitbox Details")
	UStaticMeshComponent * hitbox;

	//material of the hibox object
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hitbox Details")
	UMaterialInstanceDynamic * hitboxMaterial;

	//---------------------------------------------------------------------------------------------------------------

	//-----------------------------------------Damage Attributes-----------------------------------------------------

	//how much damage the attack will deal when the enemy is hit
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	float damage;

	//---------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------
	// Sets default values for this actor's properties
	AHitbox();
	//sets the values for the hitbox
	void SetHitboxProperties(EHITBOX_TYPE _hitboxType, FVector _hitboxPosition, FVector _dimensions, float _damage, bool visible);
	
	//hitbox collision function
	UFUNCTION(BlueprintCallable, Category="Hitboxes")
	void OnHit(UPrimitiveComponent* thisHitbox, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
};
