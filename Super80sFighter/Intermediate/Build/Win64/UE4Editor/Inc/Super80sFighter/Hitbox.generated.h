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
struct FHitResult;
#ifdef SUPER80SFIGHTER_Hitbox_generated_h
#error "Hitbox.generated.h already included, missing '#pragma once' in Hitbox.h"
#endif
#define SUPER80SFIGHTER_Hitbox_generated_h

#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_thisHitbox); \
		P_GET_OBJECT(AActor,Z_Param_otherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_otherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_thisHitbox,Z_Param_otherActor,Z_Param_otherComp,Z_Param_otherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_thisHitbox); \
		P_GET_OBJECT(AActor,Z_Param_otherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_otherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_otherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_thisHitbox,Z_Param_otherActor,Z_Param_otherComp,Z_Param_otherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHitbox(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AHitbox(); \
public: \
	DECLARE_CLASS(AHitbox, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AHitbox) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAHitbox(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AHitbox(); \
public: \
	DECLARE_CLASS(AHitbox, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AHitbox) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHitbox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHitbox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHitbox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHitbox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHitbox(AHitbox&&); \
	NO_API AHitbox(const AHitbox&); \
public:


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHitbox(AHitbox&&); \
	NO_API AHitbox(const AHitbox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHitbox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHitbox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHitbox)


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_PRIVATE_PROPERTY_OFFSET
#define Super80sFighter_Source_Super80sFighter_Hitbox_h_24_PROLOG
#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_RPC_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_INCLASS \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Super80sFighter_Source_Super80sFighter_Hitbox_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_INCLASS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Hitbox_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Super80sFighter_Source_Super80sFighter_Hitbox_h


#define FOREACH_ENUM_EHITBOX_TYPE(op) \
	op(EHITBOX_TYPE::VE_HITBOX_STRIKE) \
	op(EHITBOX_TYPE::VE_HITBOX_PROJECTILE) \
	op(EHITBOX_TYPE::VE_HITBOX_PROXIMITY) \
	op(EHITBOX_TYPE::VE_HITBOX_THROW) \
	op(EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
