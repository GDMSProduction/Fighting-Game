// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Super80sFighterGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuper80sFighterGameMode() {}
// Cross Module References
	SUPER80SFIGHTER_API UEnum* Z_Construct_UEnum_Super80sFighter_EInputTypes();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
	SUPER80SFIGHTER_API UEnum* Z_Construct_UEnum_Super80sFighter_EMenuState();
	SUPER80SFIGHTER_API UEnum* Z_Construct_UEnum_Super80sFighter_ECharacterEnum();
	SUPER80SFIGHTER_API UScriptStruct* Z_Construct_UScriptStruct_FHighScore();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_ASuper80sFighterGameMode_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_ASuper80sFighterGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ConvertKeyToString();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_draw();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_GetBindingKey();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_GetIsKeyboardMode();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideAxisInput();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideKeyInput();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputs();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputsWrapper();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_SetIsKeyboardMode();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AFighterParent_NoRegister();
// End Cross Module References
	static UEnum* EInputTypes_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Super80sFighter_EInputTypes, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("EInputTypes"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EInputTypes(EInputTypes_StaticEnum, TEXT("/Script/Super80sFighter"), TEXT("EInputTypes"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Super80sFighter_EInputTypes_CRC() { return 3249842498U; }
	UEnum* Z_Construct_UEnum_Super80sFighter_EInputTypes()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EInputTypes"), 0, Get_Z_Construct_UEnum_Super80sFighter_EInputTypes_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EInputTypes::JUMP", (int64)EInputTypes::JUMP },
				{ "EInputTypes::CROUCH", (int64)EInputTypes::CROUCH },
				{ "EInputTypes::LEFT", (int64)EInputTypes::LEFT },
				{ "EInputTypes::RIGHT", (int64)EInputTypes::RIGHT },
				{ "EInputTypes::ATT1", (int64)EInputTypes::ATT1 },
				{ "EInputTypes::ATT2", (int64)EInputTypes::ATT2 },
				{ "EInputTypes::ATT3", (int64)EInputTypes::ATT3 },
				{ "EInputTypes::ATT4", (int64)EInputTypes::ATT4 },
				{ "EInputTypes::PUNCHANDKICK", (int64)EInputTypes::PUNCHANDKICK },
				{ "EInputTypes::KICKANDSPECIAL", (int64)EInputTypes::KICKANDSPECIAL },
				{ "EInputTypes::NUMOFINPUTTYPES", (int64)EInputTypes::NUMOFINPUTTYPES },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Super80sFighter,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EInputTypes",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EInputTypes",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EMenuState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Super80sFighter_EMenuState, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("EMenuState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMenuState(EMenuState_StaticEnum, TEXT("/Script/Super80sFighter"), TEXT("EMenuState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Super80sFighter_EMenuState_CRC() { return 786138900U; }
	UEnum* Z_Construct_UEnum_Super80sFighter_EMenuState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMenuState"), 0, Get_Z_Construct_UEnum_Super80sFighter_EMenuState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EMenuState::STATE_SPLASH", (int64)EMenuState::STATE_SPLASH },
				{ "EMenuState::STATE_MENU", (int64)EMenuState::STATE_MENU },
				{ "EMenuState::STATE_CHAR_SELECT", (int64)EMenuState::STATE_CHAR_SELECT },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
				{ "STATE_CHAR_SELECT.DisplayName", "Character Select" },
				{ "STATE_MENU.DisplayName", "Menu" },
				{ "STATE_SPLASH.DisplayName", "Splash" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Super80sFighter,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EMenuState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EMenuState",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ECharacterEnum_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Super80sFighter_ECharacterEnum, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("ECharacterEnum"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ECharacterEnum(ECharacterEnum_StaticEnum, TEXT("/Script/Super80sFighter"), TEXT("ECharacterEnum"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Super80sFighter_ECharacterEnum_CRC() { return 2819079786U; }
	UEnum* Z_Construct_UEnum_Super80sFighter_ECharacterEnum()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ECharacterEnum"), 0, Get_Z_Construct_UEnum_Super80sFighter_ECharacterEnum_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ECharacterEnum::CLASS_DEFAULT", (int64)ECharacterEnum::CLASS_DEFAULT },
				{ "ECharacterEnum::CLASS_THUG", (int64)ECharacterEnum::CLASS_THUG },
				{ "ECharacterEnum::CLASS_TOBY", (int64)ECharacterEnum::CLASS_TOBY },
				{ "ECharacterEnum::CLASS_TREY", (int64)ECharacterEnum::CLASS_TREY },
				{ "ECharacterEnum::CLASS_AUDREY", (int64)ECharacterEnum::CLASS_AUDREY },
				{ "ECharacterEnum::CLASS_ORION", (int64)ECharacterEnum::CLASS_ORION },
				{ "ECharacterEnum::CLASS_BRRIDER", (int64)ECharacterEnum::CLASS_BRRIDER },
				{ "ECharacterEnum::CLASS_GEORGE", (int64)ECharacterEnum::CLASS_GEORGE },
				{ "ECharacterEnum::CLASS_TYPHOON", (int64)ECharacterEnum::CLASS_TYPHOON },
				{ "ECharacterEnum::CLASS_DON", (int64)ECharacterEnum::CLASS_DON },
				{ "ECharacterEnum::CLASS_KARMA", (int64)ECharacterEnum::CLASS_KARMA },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "CLASS_AUDREY.DisplayName", "Audrey" },
				{ "CLASS_BRRIDER.DisplayName", "BRRider" },
				{ "CLASS_DEFAULT.DisplayName", "Base" },
				{ "CLASS_DON.DisplayName", "Don" },
				{ "CLASS_GEORGE.DisplayName", "George" },
				{ "CLASS_KARMA.DisplayName", "Karma" },
				{ "CLASS_ORION.DisplayName", "Orion" },
				{ "CLASS_THUG.DisplayName", "Thug" },
				{ "CLASS_TOBY.DisplayName", "Toby" },
				{ "CLASS_TREY.DisplayName", "Trey" },
				{ "CLASS_TYPHOON.DisplayName", "Typhoon" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Super80sFighter,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ECharacterEnum",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ECharacterEnum",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FHighScore::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SUPER80SFIGHTER_API uint32 Get_Z_Construct_UScriptStruct_FHighScore_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FHighScore, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("HighScore"), sizeof(FHighScore), Get_Z_Construct_UScriptStruct_FHighScore_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FHighScore(FHighScore::StaticStruct, TEXT("/Script/Super80sFighter"), TEXT("HighScore"), false, nullptr, nullptr);
static struct FScriptStruct_Super80sFighter_StaticRegisterNativesFHighScore
{
	FScriptStruct_Super80sFighter_StaticRegisterNativesFHighScore()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("HighScore")),new UScriptStruct::TCppStructOps<FHighScore>);
	}
} ScriptStruct_Super80sFighter_StaticRegisterNativesFHighScore;
	UScriptStruct* Z_Construct_UScriptStruct_FHighScore()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FHighScore_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("HighScore"), sizeof(FHighScore), Get_Z_Construct_UScriptStruct_FHighScore_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHighScore>(); };
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"HighScore",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FHighScore),
				alignof(FHighScore),
				nullptr, 0,
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FHighScore_CRC() { return 962374204U; }
	void ASuper80sFighterGameMode::StaticRegisterNativesASuper80sFighterGameMode()
	{
		UClass* Class = ASuper80sFighterGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertKeyToString", (Native)&ASuper80sFighterGameMode::execConvertKeyToString },
			{ "draw", (Native)&ASuper80sFighterGameMode::execdraw },
			{ "GetBindingKey", (Native)&ASuper80sFighterGameMode::execGetBindingKey },
			{ "GetIsKeyboardMode", (Native)&ASuper80sFighterGameMode::execGetIsKeyboardMode },
			{ "OverrideAxisInput", (Native)&ASuper80sFighterGameMode::execOverrideAxisInput },
			{ "OverrideKeyInput", (Native)&ASuper80sFighterGameMode::execOverrideKeyInput },
			{ "ResetInputs", (Native)&ASuper80sFighterGameMode::execResetInputs },
			{ "ResetInputsWrapper", (Native)&ASuper80sFighterGameMode::execResetInputsWrapper },
			{ "SetIsKeyboardMode", (Native)&ASuper80sFighterGameMode::execSetIsKeyboardMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ConvertKeyToString()
	{
		struct Super80sFighterGameMode_eventConvertKeyToString_Parms
		{
			FKey inKey;
			FString ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Str, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventConvertKeyToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_inKey = { UE4CodeGen_Private::EPropertyClass::Struct, "inKey", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventConvertKeyToString_Parms, inKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inKey,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "ConvertKeyToString", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventConvertKeyToString_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_draw()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "draw", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_GetBindingKey()
	{
		struct Super80sFighterGameMode_eventGetBindingKey_Parms
		{
			EInputTypes m_Type;
			bool isPlayer1;
			FKey ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventGetBindingKey_Parms, ReturnValue), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_isPlayer1_SetBit = [](void* Obj){ ((Super80sFighterGameMode_eventGetBindingKey_Parms*)Obj)->isPlayer1 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isPlayer1 = { UE4CodeGen_Private::EPropertyClass::Bool, "isPlayer1", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Super80sFighterGameMode_eventGetBindingKey_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isPlayer1_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_m_Type = { UE4CodeGen_Private::EPropertyClass::Enum, "m_Type", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventGetBindingKey_Parms, m_Type), Z_Construct_UEnum_Super80sFighter_EInputTypes, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_m_Type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isPlayer1,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_m_Type,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_m_Type_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "GetBindingKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventGetBindingKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_GetIsKeyboardMode()
	{
		struct Super80sFighterGameMode_eventGetIsKeyboardMode_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((Super80sFighterGameMode_eventGetIsKeyboardMode_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Super80sFighterGameMode_eventGetIsKeyboardMode_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "GetIsKeyboardMode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventGetIsKeyboardMode_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideAxisInput()
	{
		struct Super80sFighterGameMode_eventOverrideAxisInput_Parms
		{
			FKey inputKey;
			FString InputName;
			float axisScaler;
			bool shouldWeErase;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_shouldWeErase_SetBit = [](void* Obj){ ((Super80sFighterGameMode_eventOverrideAxisInput_Parms*)Obj)->shouldWeErase = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_shouldWeErase = { UE4CodeGen_Private::EPropertyClass::Bool, "shouldWeErase", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Super80sFighterGameMode_eventOverrideAxisInput_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_shouldWeErase_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_axisScaler = { UE4CodeGen_Private::EPropertyClass::Float, "axisScaler", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventOverrideAxisInput_Parms, axisScaler), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_InputName = { UE4CodeGen_Private::EPropertyClass::Str, "InputName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventOverrideAxisInput_Parms, InputName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_inputKey = { UE4CodeGen_Private::EPropertyClass::Struct, "inputKey", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventOverrideAxisInput_Parms, inputKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_shouldWeErase,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_axisScaler,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InputName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inputKey,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "OverrideAxisInput", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventOverrideAxisInput_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideKeyInput()
	{
		struct Super80sFighterGameMode_eventOverrideKeyInput_Parms
		{
			FKey inputKey;
			FString InputName;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_InputName = { UE4CodeGen_Private::EPropertyClass::Str, "InputName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventOverrideKeyInput_Parms, InputName), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_inputKey = { UE4CodeGen_Private::EPropertyClass::Struct, "inputKey", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Super80sFighterGameMode_eventOverrideKeyInput_Parms, inputKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InputName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inputKey,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "OverrideKeyInput", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventOverrideKeyInput_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "ResetInputs", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020601, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputsWrapper()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "ResetInputsWrapper", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASuper80sFighterGameMode_SetIsKeyboardMode()
	{
		struct Super80sFighterGameMode_eventSetIsKeyboardMode_Parms
		{
			bool m_SetKeyboardMode;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_m_SetKeyboardMode_SetBit = [](void* Obj){ ((Super80sFighterGameMode_eventSetIsKeyboardMode_Parms*)Obj)->m_SetKeyboardMode = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_SetKeyboardMode = { UE4CodeGen_Private::EPropertyClass::Bool, "m_SetKeyboardMode", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Super80sFighterGameMode_eventSetIsKeyboardMode_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_m_SetKeyboardMode_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_m_SetKeyboardMode,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuper80sFighterGameMode, "SetIsKeyboardMode", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Super80sFighterGameMode_eventSetIsKeyboardMode_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASuper80sFighterGameMode_NoRegister()
	{
		return ASuper80sFighterGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ASuper80sFighterGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_ConvertKeyToString, "ConvertKeyToString" }, // 1365962047
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_draw, "draw" }, // 1750238711
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_GetBindingKey, "GetBindingKey" }, // 3293486808
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_GetIsKeyboardMode, "GetIsKeyboardMode" }, // 3861641157
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideAxisInput, "OverrideAxisInput" }, // 1955936202
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_OverrideKeyInput, "OverrideKeyInput" }, // 1208651145
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputs, "ResetInputs" }, // 1947594286
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_ResetInputsWrapper, "ResetInputsWrapper" }, // 3416976000
				{ &Z_Construct_UFunction_ASuper80sFighterGameMode_SetIsKeyboardMode, "SetIsKeyboardMode" }, // 1841573279
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "Super80sFighterGameMode.h" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_on_death_pause_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			auto NewProp_on_death_pause_SetBit = [](void* Obj){ ((ASuper80sFighterGameMode*)Obj)->on_death_pause = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_on_death_pause = { UE4CodeGen_Private::EPropertyClass::Bool, "on_death_pause", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ASuper80sFighterGameMode), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_on_death_pause_SetBit)>::SetBit, METADATA_PARAMS(NewProp_on_death_pause_MetaData, ARRAY_COUNT(NewProp_on_death_pause_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Player2_round_wins_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Player2_round_wins = { UE4CodeGen_Private::EPropertyClass::Int, "Player2_round_wins", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020015, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, Player2_round_wins), METADATA_PARAMS(NewProp_Player2_round_wins_MetaData, ARRAY_COUNT(NewProp_Player2_round_wins_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Player1_round_wins_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Player1_round_wins = { UE4CodeGen_Private::EPropertyClass::Int, "Player1_round_wins", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020015, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, Player1_round_wins), METADATA_PARAMS(NewProp_Player1_round_wins_MetaData, ARRAY_COUNT(NewProp_Player1_round_wins_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerWidget_MetaData[] = {
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerWidget = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerWidget", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, PlayerWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(NewProp_PlayerWidget_MetaData, ARRAY_COUNT(NewProp_PlayerWidget_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThugClass_MetaData[] = {
				{ "BlueprintProtected", "true" },
				{ "Category", "Players" },
				{ "DisplayName", "Players" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ThugClass = { UE4CodeGen_Private::EPropertyClass::Class, "ThugClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, ThugClass), Z_Construct_UClass_AFighterParent_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ThugClass_MetaData, ARRAY_COUNT(NewProp_ThugClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerHUDClass_MetaData[] = {
				{ "BlueprintProtected", "true" },
				{ "Category", "Stats" },
				{ "DisplayName", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PlayerHUDClass = { UE4CodeGen_Private::EPropertyClass::Class, "PlayerHUDClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, PlayerHUDClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_PlayerHUDClass_MetaData, ARRAY_COUNT(NewProp_PlayerHUDClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_current_menu_state_MetaData[] = {
				{ "Category", "Menu" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_current_menu_state = { UE4CodeGen_Private::EPropertyClass::Enum, "current_menu_state", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, current_menu_state), Z_Construct_UEnum_Super80sFighter_EMenuState, METADATA_PARAMS(NewProp_current_menu_state_MetaData, ARRAY_COUNT(NewProp_current_menu_state_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_current_menu_state_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_p2_type_MetaData[] = {
				{ "Category", "Characters" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_p2_type = { UE4CodeGen_Private::EPropertyClass::Enum, "p2_type", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, p2_type), Z_Construct_UEnum_Super80sFighter_ECharacterEnum, METADATA_PARAMS(NewProp_p2_type_MetaData, ARRAY_COUNT(NewProp_p2_type_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_p2_type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_p1_type_MetaData[] = {
				{ "Category", "Characters" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_p1_type = { UE4CodeGen_Private::EPropertyClass::Enum, "p1_type", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, p1_type), Z_Construct_UEnum_Super80sFighter_ECharacterEnum, METADATA_PARAMS(NewProp_p1_type_MetaData, ARRAY_COUNT(NewProp_p1_type_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_p1_type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rounds_remaining_MetaData[] = {
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_rounds_remaining = { UE4CodeGen_Private::EPropertyClass::Int, "rounds_remaining", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, rounds_remaining), METADATA_PARAMS(NewProp_rounds_remaining_MetaData, ARRAY_COUNT(NewProp_rounds_remaining_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_num_rounds_MetaData[] = {
				{ "Category", "Rounds" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_num_rounds = { UE4CodeGen_Private::EPropertyClass::Int, "num_rounds", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ASuper80sFighterGameMode, num_rounds), METADATA_PARAMS(NewProp_num_rounds_MetaData, ARRAY_COUNT(NewProp_num_rounds_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_paused_MetaData[] = {
				{ "Category", "Pause" },
				{ "ModuleRelativePath", "Super80sFighterGameMode.h" },
			};
#endif
			auto NewProp_paused_SetBit = [](void* Obj){ ((ASuper80sFighterGameMode*)Obj)->paused = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_paused = { UE4CodeGen_Private::EPropertyClass::Bool, "paused", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ASuper80sFighterGameMode), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_paused_SetBit)>::SetBit, METADATA_PARAMS(NewProp_paused_MetaData, ARRAY_COUNT(NewProp_paused_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_on_death_pause,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Player2_round_wins,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Player1_round_wins,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerWidget,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ThugClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerHUDClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_current_menu_state,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_current_menu_state_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_p2_type,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_p2_type_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_p1_type,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_p1_type_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_rounds_remaining,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_num_rounds,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_paused,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ASuper80sFighterGameMode>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ASuper80sFighterGameMode::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00880288u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASuper80sFighterGameMode, 3654315727);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASuper80sFighterGameMode(Z_Construct_UClass_ASuper80sFighterGameMode, &ASuper80sFighterGameMode::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("ASuper80sFighterGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuper80sFighterGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
