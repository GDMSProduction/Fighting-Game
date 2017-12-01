// Fill out your copyright notice in the Description page of Project Settings.

#include "Hitbox.h"
#include "Components/BoxComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
AHitbox::AHitbox()
{
 	// Set base attributes
	hitboxType = EHITBOX_TYPE::VE_HITBOX_STRIKE;
	damage = 10.0f;
	hitboxPosition.X = 0.0f;
	hitboxPosition.Y = 0.0f;
	hitboxPosition.Z = 0.0f;
	showHitbox = true;
	PrimaryActorTick.bCanEverTick = true;

	//set created variables (necessary to form the object)
	FVector hitboxDimensions(1, 1, 1);

	//create the hitbox mesh component
	hitbox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("hitboxMeshComponent"));
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (meshAsset.Object != nullptr)
	{
		hitbox->SetStaticMesh(meshAsset.Object);
	}

	//create a UMaterialInstanceDynamic for our mesh
	static auto hitboxMaterialTemp = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/SideScrollerCPP/Hitbox.Hitbox'"));
	hitboxMaterial = UMaterialInstanceDynamic::Create(hitboxMaterialTemp.Object, NULL);

	hitbox->SetMaterial(0, hitboxMaterial);

	//set collision types for the mesh and the actual hitbox
	hitbox->SetCollisionProfileName(TEXT("OverlapAll"));

	//set the hitbox to call OnHit when triggered
	hitbox->bGenerateOverlapEvents = true;
	hitbox->OnComponentBeginOverlap.AddDynamic(this, &AHitbox::OnHit);

	RootComponent = hitbox;

	//disable the hitbox (will be enabled at the appropriate time in the animation)
}

void AHitbox::SetHitboxProperties(EHITBOX_TYPE _hitboxType, FVector _hitboxPosition, FVector dimensions, float _damage)
{
	hitboxType = _hitboxType;
	damage = _damage;
	hitboxPosition = _hitboxPosition;
	hitboxPosition += GetTransform().GetLocation();

	//set dimensions
	FVector hitboxDimensions = dimensions;

	//change the properties of the hitbox
	RootComponent->SetRelativeScale3D(hitboxDimensions);
	//reenable this if we decide not to have hitboxes move with the player
	//if (RootComponent->GetAttachParent() == nullptr)
	//	RootComponent->SetWorldLocation(hitboxPosition);
	//else
	RootComponent->SetRelativeLocation(_hitboxPosition);

	//determine the color of this hitbox
	switch (hitboxType)
	{
	case EHITBOX_TYPE::VE_HITBOX_STRIKE: //red
		color.A = 127;
		color.R = 255;
		color.G = 0;
		color.B = 0;
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROJECTILE: //orange
		color.A = 127;
		color.R = 255;
		color.G = 127;
		color.B = 0;
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROXIMITY: //yellow
		color.A = 127;
		color.R = 255;
		color.G = 255;
		color.B = 0;
		break;
	case EHITBOX_TYPE::VE_HITBOX_THROW: //blue
		color.A = 127;
		color.R = 0;
		color.G = 0;
		color.B = 255;
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX: //green
		color.A = 127;
		color.R = 0;
		color.G = 255;
		color.B = 0;
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX: //purple
		color.A = 127;
		color.R = 127;
		color.G = 127;
		color.B = 127;
		break;
	default:
		break;
	}
	hitboxMaterial->SetVectorParameterValue(FName(TEXT("Base Color")), color);
	//disable the hitbox (will be enabled at the appropriate time in the animation)
	//hitbox->SetActive(false);

	//debugging stuff, delete before final version
	TArray<AActor*> actors;
	hitbox->GetOverlappingActors(actors);
	UE_LOG(LogTemp, Warning, TEXT("%d"), actors.Num());
	//hitbox->SetActive(false);
}

void AHitbox::OnHit(UPrimitiveComponent * thisHitbox, AActor * otherActor, UPrimitiveComponent * otherComp, int32 otherBodyIndex,  bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("possibly colliding with something"));
	//other actor isnt null or us
	if ((otherActor != nullptr) && (otherActor != this) && (otherComp != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("collided with something"));
		//check if the actor is a hitbox
		if (otherActor->IsA(AHitbox::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("collided with a hitbox"));
			AHitbox * otherHitbox = (AHitbox*)otherActor;
			switch (hitboxType)
			{
			case EHITBOX_TYPE::VE_HITBOX_STRIKE:
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
					//deal damage and stun enemy (maybe)... implement function for damage
					UE_LOG(LogTemp, Warning, TEXT("Strike has hit painbox, deal damage"));
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX: //do nothing
					break;
				default:
					break;
				}
				break;
			case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
					//deal damage and stun enemy (maybe)... implement function for damage
					UE_LOG(LogTemp, Warning, TEXT("Projectile has hit painbox, deal damage"));
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX: //do nothing
					break;
				default:
					break;
				}
				break;
			case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
					//if enemy is in neutral state, start blocking
					UE_LOG(LogTemp, Warning, TEXT("Proximity box has hit painbox, if enemy is in neutral start blocking"));
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX: //do nothing
					break;
				default:
					break;
				}
				break;
			case EHITBOX_TYPE::VE_HITBOX_THROW:
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX: //do nothing
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
					//throw enemy
					UE_LOG(LogTemp, Warning, TEXT("Throw box has hit enemy throw area, begin throw"));
					break;
				default:
					break;
				}
				break;
			case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX: //do nothing, functions are called on attacking boxes
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE:
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW:
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
					break;
				default:
					break;
				}
				break;
			case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX: //do nothing, functions are called on attacking boxes
				switch (otherHitbox->hitboxType)
				{
				case EHITBOX_TYPE::VE_HITBOX_STRIKE:
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
					break;
				case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
					break;
				case EHITBOX_TYPE::VE_HITBOX_THROW:
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
					break;
				case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
					break;
				default:
					break;
				}
				break;
			default:
				//this shouldn't ever happen, throw a log error
				UE_LOG(LogTemp, Warning, TEXT("ERROR: ONHIT FUNCTION REACHED DEFAULT IN SWITCH... THIS IS BAD... CONTACT DAVID CRANE AND ASK HIM WHAT HE DID WRONG"));
				break;
			}
		}
	}
}

void AHitbox::beginStartup()
{
	switch (hitboxType)
	{
	case EHITBOX_TYPE::VE_HITBOX_STRIKE:
		//do nothing for strike hitboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
		//do nothing for projectile hitboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
		//activate the proximity hitbox
		hitbox->SetActive(true);
		break;
	case EHITBOX_TYPE::VE_HITBOX_THROW:
		//do nothing for throw hitboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
		//do nothing for painboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
		//do nothing for throwboxes
		break;
	default:
		break;
	}
}

void AHitbox::beginActive()
{
	switch (hitboxType)
	{
	case EHITBOX_TYPE::VE_HITBOX_STRIKE:
		//set strike hitboxes to be active
		hitbox->SetActive(true);
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
		//set projectile hitboxes to be active
		hitbox->SetActive(true);
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
		//do nothing for proximity hitboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_THROW:
		//set throw hitboxes to be active
		hitbox->SetActive(true);
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
		//do nothing for painboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
		//do nothing for throwboxes
		break;
	default:
		break;
	}
}

void AHitbox::beginRecovery()
{
	switch (hitboxType)
	{
	case EHITBOX_TYPE::VE_HITBOX_STRIKE:
		//set strike hitboxes to be inactive
		hitbox->SetActive(false);
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
		//do nothing for projectile hitboxes (these will be destroyed when the projectile itself is destroyed)
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
		//set proximity hitboxes to be inactive
		hitbox->SetActive(false);
		break;
	case EHITBOX_TYPE::VE_HITBOX_THROW:
		//set throw hitboxes to be inactive
		hitbox->SetActive(false);
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
		//do nothing for painboxes
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
		//do nothing for throwboxes
		break;
	default:
		break;
	}
}

void AHitbox::end()
{
	switch (hitboxType)
	{
	case EHITBOX_TYPE::VE_HITBOX_STRIKE:
		//destroy the strike hitbox
		Destroy();
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROJECTILE:
		//do nothing for projectile hitboxes (these will be destroyed when the projectile itself is destroyed)
		break;
	case EHITBOX_TYPE::VE_HITBOX_PROXIMITY:
		//destroy the proximity hitbox
		Destroy();
		break;
	case EHITBOX_TYPE::VE_HITBOX_THROW:
		//destroy the throw hitbox
		Destroy();
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX:
		//do nothing for the painbox
		break;
	case EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX:
		//do nothing for the throwbox
		break;
	default:
		break;
	}
}

// Called when the game starts or when spawned
void AHitbox::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

