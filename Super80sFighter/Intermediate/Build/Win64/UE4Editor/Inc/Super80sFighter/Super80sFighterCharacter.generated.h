// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
struct FKey;
enum class EHITBOX_TYPE : uint8;
class AHitbox;
#ifdef SUPER80SFIGHTER_Super80sFighterCharacter_generated_h
#error "Super80sFighterCharacter.generated.h already included, missing '#pragma once' in Super80sFighterCharacter.h"
#endif
#define SUPER80SFIGHTER_Super80sFighterCharacter_generated_h

#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_30_GENERATED_BODY \
	friend SUPER80SFIGHTER_API class UScriptStruct* Z_Construct_UScriptStruct_FScoreSystem(); \
	SUPER80SFIGHTER_API static class UScriptStruct* StaticStruct();


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execdestroy) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->destroy(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTauntStaminaRegen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TauntStaminaRegen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStaminaRegen) \
	{ \
		P_GET_UBOOL(Z_Param_tf); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetStaminaRegen(Z_Param_tf); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSuperAbility) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SuperAbility(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectakeDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->takeDamage(Z_Param_damage); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCurrentHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCurrentHealth(Z_Param_Health); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execonHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->onHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTotalHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTotalHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCurrentStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Stamina); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCurrentStamina(Z_Param_Stamina); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTotalStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTotalStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLastPressedKey) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FKey*)Z_Param__Result=this->GetLastPressedKey(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLastPressedKey) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetLastPressedKey(Z_Param_inKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execspawnHitbox) \
	{ \
		P_GET_ENUM(EHITBOX_TYPE,Z_Param_type); \
		P_GET_STRUCT(FVector,Z_Param_offset); \
		P_GET_STRUCT(FVector,Z_Param_dimensions); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_GET_UBOOL(Z_Param_visible); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHitbox**)Z_Param__Result=this->spawnHitbox(EHITBOX_TYPE(Z_Param_type),Z_Param_offset,Z_Param_dimensions,Z_Param_damage,Z_Param_visible); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execdestroy) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->destroy(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTauntStaminaRegen) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TauntStaminaRegen(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStaminaRegen) \
	{ \
		P_GET_UBOOL(Z_Param_tf); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetStaminaRegen(Z_Param_tf); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSuperAbility) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SuperAbility(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(exectakeDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->takeDamage(Z_Param_damage); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCurrentHealth) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Health); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCurrentHealth(Z_Param_Health); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execonHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->onHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTotalHealth) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTotalHealth(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateCurrentStamina) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Stamina); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateCurrentStamina(Z_Param_Stamina); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTotalStamina) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTotalStamina(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLastPressedKey) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FKey*)Z_Param__Result=this->GetLastPressedKey(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLastPressedKey) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetLastPressedKey(Z_Param_inKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execspawnHitbox) \
	{ \
		P_GET_ENUM(EHITBOX_TYPE,Z_Param_type); \
		P_GET_STRUCT(FVector,Z_Param_offset); \
		P_GET_STRUCT(FVector,Z_Param_dimensions); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_GET_UBOOL(Z_Param_visible); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AHitbox**)Z_Param__Result=this->spawnHitbox(EHITBOX_TYPE(Z_Param_type),Z_Param_offset,Z_Param_dimensions,Z_Param_damage,Z_Param_visible); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_EVENT_PARMS
#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_CALLBACK_WRAPPERS
#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFighterParent(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AFighterParent(); \
public: \
	DECLARE_CLASS(AFighterParent, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AFighterParent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_INCLASS \
private: \
	static void StaticRegisterNativesAFighterParent(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AFighterParent(); \
public: \
	DECLARE_CLASS(AFighterParent, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AFighterParent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFighterParent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFighterParent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFighterParent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFighterParent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFighterParent(AFighterParent&&); \
	NO_API AFighterParent(const AFighterParent&); \
public:


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFighterParent(AFighterParent&&); \
	NO_API AFighterParent(const AFighterParent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFighterParent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFighterParent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFighterParent)


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(AFighterParent, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AFighterParent, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__tempHitbox() { return STRUCT_OFFSET(AFighterParent, tempHitbox); } \
	FORCEINLINE static uint32 __PPO__TotalStamina() { return STRUCT_OFFSET(AFighterParent, TotalStamina); } \
	FORCEINLINE static uint32 __PPO__CurrentStamina() { return STRUCT_OFFSET(AFighterParent, CurrentStamina); } \
	FORCEINLINE static uint32 __PPO__TotalHealth() { return STRUCT_OFFSET(AFighterParent, TotalHealth); } \
	FORCEINLINE static uint32 __PPO__CurrentHealth() { return STRUCT_OFFSET(AFighterParent, CurrentHealth); } \
	FORCEINLINE static uint32 __PPO__hitboxes() { return STRUCT_OFFSET(AFighterParent, hitboxes); } \
	FORCEINLINE static uint32 __PPO__IsFacingRight() { return STRUCT_OFFSET(AFighterParent, IsFacingRight); } \
	FORCEINLINE static uint32 __PPO__initialSelector() { return STRUCT_OFFSET(AFighterParent, initialSelector); } \
	FORCEINLINE static uint32 __PPO__initialCounter() { return STRUCT_OFFSET(AFighterParent, initialCounter); } \
	FORCEINLINE static uint32 __PPO__initial2Counter() { return STRUCT_OFFSET(AFighterParent, initial2Counter); } \
	FORCEINLINE static uint32 __PPO__initial3Counter() { return STRUCT_OFFSET(AFighterParent, initial3Counter); } \
	FORCEINLINE static uint32 __PPO__grounded() { return STRUCT_OFFSET(AFighterParent, grounded); }


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_78_PROLOG \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_EVENT_PARMS


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_RPC_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_CALLBACK_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_INCLASS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_CALLBACK_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_INCLASS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h_82_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Super80sFighter_Source_Super80sFighter_Super80sFighterCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
