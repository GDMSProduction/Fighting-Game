// Fill out your copyright notice in the Description page of Project Settings.

#include "Hitbox.h"
#include "Components/BoxComponent.h"

// Sets default values
AHitbox::AHitbox()
{
 	// Set base attributes
	hitboxType = EHITBOX_TYPE::VE_HITBOX_STRIKE;
	hitboxWidth = 2.0f;
	hitboxHeight = 2.0f;
	hitboxDepth = 3.0f;
	damage = 10.0f;
	hitboxPosition.X = 0.0f;
	hitboxPosition.Y = 0.0f;
	hitboxPosition.Z = 0.0f;

	//set created variables (necessary to form the object)
	FVector hitboxDimensions;
	hitboxDimensions.X = hitboxDepth;
	hitboxDimensions.Y = hitboxWidth;
	hitboxDimensions.Z = hitboxHeight;

	//instantiate the hitbox itself
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("hitboxShapeComponent"));
	hitbox->SetBoxExtent(hitboxDimensions);
	hitbox->AddRelativeLocation(hitboxPosition);

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
	RootComponent = hitbox;
	//disable the hitbox (will be enabled at the appropriate time in the animation)
	//hitbox->SetActive(false);
}

AHitbox::AHitbox(EHITBOX_TYPE _hitboxType, FVector _hitboxPosition, float _hWidth, float _hHeight, float _damage)
{
	hitboxType = _hitboxType;
	hitboxWidth = _hWidth;
	hitboxHeight = _hHeight;
	damage = _damage;
	hitboxPosition = _hitboxPosition;

	//set created variables (necessary to form the object)
	FVector hitboxDimensions;
	hitboxDimensions.X = hitboxDepth;
	hitboxDimensions.Y = hitboxWidth;
	hitboxDimensions.Z = hitboxHeight;

	//instantiate the hitbox itself
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("hitboxShapeComponent"));
	hitbox->SetWorldScale3D(hitboxDimensions);
	hitbox->AddRelativeLocation(hitboxPosition);

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
	RootComponent = hitbox;
	//disable the hitbox (will be enabled at the appropriate time in the animation)
	//hitbox->SetActive(false);
}

void AHitbox::SetHitboxProperties(EHITBOX_TYPE _hitboxType, FVector _hitboxPosition, float _hWidth, float _hHeight, float _damage)
{
	hitboxType = _hitboxType;
	hitboxWidth = _hWidth;
	hitboxHeight = _hHeight;
	damage = _damage;
	hitboxPosition = _hitboxPosition;

	//set dimensions
	FVector hitboxDimensions;
	hitboxDimensions.X = hitboxDepth;
	hitboxDimensions.Y = hitboxWidth;
	hitboxDimensions.Z = hitboxHeight;

	//change the properties of the hitbox
	hitbox->SetBoxExtent(hitboxDimensions);
	hitbox->AddRelativeLocation(hitboxPosition);

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

	//disable the hitbox (will be enabled at the appropriate time in the animation)
	//hitbox->SetActive(false);
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

