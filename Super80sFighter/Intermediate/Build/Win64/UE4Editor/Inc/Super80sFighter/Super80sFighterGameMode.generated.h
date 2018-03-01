// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EInputTypes : uint8;
struct FKey;
#ifdef SUPER80SFIGHTER_Super80sFighterGameMode_generated_h
#error "Super80sFighterGameMode.generated.h already included, missing '#pragma once' in Super80sFighterGameMode.h"
#endif
#define SUPER80SFIGHTER_Super80sFighterGameMode_generated_h

#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_62_GENERATED_BODY \
	friend SUPER80SFIGHTER_API class UScriptStruct* Z_Construct_UScriptStruct_FHighScore(); \
	SUPER80SFIGHTER_API static class UScriptStruct* StaticStruct();


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execdraw) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->draw(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetInputsWrapper) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetInputsWrapper(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetInputs) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetInputs(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIsKeyboardMode) \
	{ \
		P_GET_UBOOL(Z_Param_m_SetKeyboardMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetIsKeyboardMode(Z_Param_m_SetKeyboardMode); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsKeyboardMode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsKeyboardMode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBindingKey) \
	{ \
		P_GET_ENUM(EInputTypes,Z_Param_m_Type); \
		P_GET_UBOOL(Z_Param_isPlayer1); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FKey*)Z_Param__Result=this->GetBindingKey(EInputTypes(Z_Param_m_Type),Z_Param_isPlayer1); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertKeyToString) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=this->ConvertKeyToString(Z_Param_inKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverrideAxisInput) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inputKey); \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_axisScaler); \
		P_GET_UBOOL(Z_Param_shouldWeErase); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverrideAxisInput(Z_Param_inputKey,Z_Param_InputName,Z_Param_axisScaler,Z_Param_shouldWeErase); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverrideKeyInput) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inputKey); \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverrideKeyInput(Z_Param_inputKey,Z_Param_InputName); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execdraw) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->draw(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetInputsWrapper) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetInputsWrapper(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetInputs) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetInputs(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetIsKeyboardMode) \
	{ \
		P_GET_UBOOL(Z_Param_m_SetKeyboardMode); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetIsKeyboardMode(Z_Param_m_SetKeyboardMode); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsKeyboardMode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsKeyboardMode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBindingKey) \
	{ \
		P_GET_ENUM(EInputTypes,Z_Param_m_Type); \
		P_GET_UBOOL(Z_Param_isPlayer1); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FKey*)Z_Param__Result=this->GetBindingKey(EInputTypes(Z_Param_m_Type),Z_Param_isPlayer1); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConvertKeyToString) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inKey); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=this->ConvertKeyToString(Z_Param_inKey); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverrideAxisInput) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inputKey); \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_axisScaler); \
		P_GET_UBOOL(Z_Param_shouldWeErase); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverrideAxisInput(Z_Param_inputKey,Z_Param_InputName,Z_Param_axisScaler,Z_Param_shouldWeErase); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverrideKeyInput) \
	{ \
		P_GET_STRUCT(FKey,Z_Param_inputKey); \
		P_GET_PROPERTY(UStrProperty,Z_Param_InputName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OverrideKeyInput(Z_Param_inputKey,Z_Param_InputName); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASuper80sFighterGameMode(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_ASuper80sFighterGameMode(); \
public: \
	DECLARE_CLASS(ASuper80sFighterGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Super80sFighter"), SUPER80SFIGHTER_API) \
	DECLARE_SERIALIZER(ASuper80sFighterGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_INCLASS \
private: \
	static void StaticRegisterNativesASuper80sFighterGameMode(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_ASuper80sFighterGameMode(); \
public: \
	DECLARE_CLASS(ASuper80sFighterGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/Super80sFighter"), SUPER80SFIGHTER_API) \
	DECLARE_SERIALIZER(ASuper80sFighterGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SUPER80SFIGHTER_API ASuper80sFighterGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASuper80sFighterGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SUPER80SFIGHTER_API, ASuper80sFighterGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuper80sFighterGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SUPER80SFIGHTER_API ASuper80sFighterGameMode(ASuper80sFighterGameMode&&); \
	SUPER80SFIGHTER_API ASuper80sFighterGameMode(const ASuper80sFighterGameMode&); \
public:


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SUPER80SFIGHTER_API ASuper80sFighterGameMode(ASuper80sFighterGameMode&&); \
	SUPER80SFIGHTER_API ASuper80sFighterGameMode(const ASuper80sFighterGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SUPER80SFIGHTER_API, ASuper80sFighterGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuper80sFighterGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASuper80sFighterGameMode)


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerHUDClass() { return STRUCT_OFFSET(ASuper80sFighterGameMode, PlayerHUDClass); } \
	FORCEINLINE static uint32 __PPO__ThugClass() { return STRUCT_OFFSET(ASuper80sFighterGameMode, ThugClass); } \
	FORCEINLINE static uint32 __PPO__PlayerWidget() { return STRUCT_OFFSET(ASuper80sFighterGameMode, PlayerWidget); } \
	FORCEINLINE static uint32 __PPO__Player1_round_wins() { return STRUCT_OFFSET(ASuper80sFighterGameMode, Player1_round_wins); } \
	FORCEINLINE static uint32 __PPO__Player2_round_wins() { return STRUCT_OFFSET(ASuper80sFighterGameMode, Player2_round_wins); } \
	FORCEINLINE static uint32 __PPO__on_death_pause() { return STRUCT_OFFSET(ASuper80sFighterGameMode, on_death_pause); }


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_79_PROLOG
#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_RPC_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_INCLASS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_RPC_WRAPPERS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_INCLASS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h_82_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Super80sFighter_Source_Super80sFighter_Super80sFighterGameMode_h


#define FOREACH_ENUM_EINPUTTYPES(op) \
	op(EInputTypes::JUMP) \
	op(EInputTypes::CROUCH) \
	op(EInputTypes::LEFT) \
	op(EInputTypes::RIGHT) \
	op(EInputTypes::ATT1) \
	op(EInputTypes::ATT2) \
	op(EInputTypes::ATT3) \
	op(EInputTypes::ATT4) \
	op(EInputTypes::PUNCHANDKICK) \
	op(EInputTypes::KICKANDSPECIAL) 
#define FOREACH_ENUM_EMENUSTATE(op) \
	op(EMenuState::STATE_SPLASH) \
	op(EMenuState::STATE_MENU) 
#define FOREACH_ENUM_ECHARACTERENUM(op) \
	op(ECharacterEnum::CLASS_DEFAULT) \
	op(ECharacterEnum::CLASS_THUG) \
	op(ECharacterEnum::CLASS_TOBY) \
	op(ECharacterEnum::CLASS_TREY) \
	op(ECharacterEnum::CLASS_AUDREY) \
	op(ECharacterEnum::CLASS_ORION) \
	op(ECharacterEnum::CLASS_BRRIDER) \
	op(ECharacterEnum::CLASS_GEORGE) \
	op(ECharacterEnum::CLASS_TYPHOON) \
	op(ECharacterEnum::CLASS_DON) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
