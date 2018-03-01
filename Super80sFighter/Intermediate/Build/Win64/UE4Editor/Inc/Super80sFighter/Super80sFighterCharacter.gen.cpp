// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Super80sFighterCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuper80sFighterCharacter() {}
// Cross Module References
	SUPER80SFIGHTER_API UScriptStruct* Z_Construct_UScriptStruct_FScoreSystem();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AFighterParent_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AFighterParent();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_BlockEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_DashEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_DeathEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_destroy();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_FirstAttackEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_FourthAttackEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_GetCurrentHealth();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_GetCurrentStamina();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_GetLastPressedKey();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_GetTotalHealth();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_GetTotalStamina();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_HighJumpEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_JumpEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_LandEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_onHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_ResetHealth();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_ResetStamina();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_SecondAttackEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_SetLastPressedKey();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_SetStaminaRegen();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_spawnHitbox();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AHitbox_NoRegister();
	SUPER80SFIGHTER_API UEnum* Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_SuperAbility();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_takeDamage();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_TakeDamageBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_TauntStaminaRegen();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_ThirdAttackEffectBlueprintEvent();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_UpdateCurrentHealth();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AFighterParent_UpdateCurrentStamina();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FScoreSystem::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SUPER80SFIGHTER_API uint32 Get_Z_Construct_UScriptStruct_FScoreSystem_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FScoreSystem, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("ScoreSystem"), sizeof(FScoreSystem), Get_Z_Construct_UScriptStruct_FScoreSystem_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FScoreSystem(FScoreSystem::StaticStruct, TEXT("/Script/Super80sFighter"), TEXT("ScoreSystem"), false, nullptr, nullptr);
static struct FScriptStruct_Super80sFighter_StaticRegisterNativesFScoreSystem
{
	FScriptStruct_Super80sFighter_StaticRegisterNativesFScoreSystem()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ScoreSystem")),new UScriptStruct::TCppStructOps<FScoreSystem>);
	}
} ScriptStruct_Super80sFighter_StaticRegisterNativesFScoreSystem;
	UScriptStruct* Z_Construct_UScriptStruct_FScoreSystem()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FScoreSystem_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ScoreSystem"), sizeof(FScoreSystem), Get_Z_Construct_UScriptStruct_FScoreSystem_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The scoring system for end-match results." },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FScoreSystem>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_specialFinish_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Was the round won with a special finish?" },
			};
#endif
			auto NewProp_specialFinish_SetBit = [](void* Obj){ ((FScoreSystem*)Obj)->specialFinish = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_specialFinish = { UE4CodeGen_Private::EPropertyClass::Bool, "specialFinish", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FScoreSystem), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_specialFinish_SetBit)>::SetBit, METADATA_PARAMS(NewProp_specialFinish_MetaData, ARRAY_COUNT(NewProp_specialFinish_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_winPerfectGame_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Was the game a win-perfect game for the player?" },
			};
#endif
			auto NewProp_winPerfectGame_SetBit = [](void* Obj){ ((FScoreSystem*)Obj)->winPerfectGame = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_winPerfectGame = { UE4CodeGen_Private::EPropertyClass::Bool, "winPerfectGame", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FScoreSystem), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_winPerfectGame_SetBit)>::SetBit, METADATA_PARAMS(NewProp_winPerfectGame_MetaData, ARRAY_COUNT(NewProp_winPerfectGame_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_perfectRound_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Was the round a perfect round for the player?" },
			};
#endif
			auto NewProp_perfectRound_SetBit = [](void* Obj){ ((FScoreSystem*)Obj)->perfectRound = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_perfectRound = { UE4CodeGen_Private::EPropertyClass::Bool, "perfectRound", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FScoreSystem), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_perfectRound_SetBit)>::SetBit, METADATA_PARAMS(NewProp_perfectRound_MetaData, ARRAY_COUNT(NewProp_perfectRound_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numAttacksBlocked_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The amount of blocked attacks after each round." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numAttacksBlocked = { UE4CodeGen_Private::EPropertyClass::Float, "numAttacksBlocked", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, numAttacksBlocked), METADATA_PARAMS(NewProp_numAttacksBlocked_MetaData, ARRAY_COUNT(NewProp_numAttacksBlocked_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numTaunts_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The number of landed special attacks throughout the match." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numTaunts = { UE4CodeGen_Private::EPropertyClass::Float, "numTaunts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, numTaunts), METADATA_PARAMS(NewProp_numTaunts_MetaData, ARRAY_COUNT(NewProp_numTaunts_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numSpecialHits_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The number of landed special attacks throughout the match." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numSpecialHits = { UE4CodeGen_Private::EPropertyClass::Float, "numSpecialHits", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, numSpecialHits), METADATA_PARAMS(NewProp_numSpecialHits_MetaData, ARRAY_COUNT(NewProp_numSpecialHits_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numHeavyHits_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The number of landed heavy attacks throughout the match." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numHeavyHits = { UE4CodeGen_Private::EPropertyClass::Float, "numHeavyHits", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, numHeavyHits), METADATA_PARAMS(NewProp_numHeavyHits_MetaData, ARRAY_COUNT(NewProp_numHeavyHits_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_numHits_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The number of landed punches and kicks throughout the match." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_numHits = { UE4CodeGen_Private::EPropertyClass::Float, "numHits", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, numHits), METADATA_PARAMS(NewProp_numHits_MetaData, ARRAY_COUNT(NewProp_numHits_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_healthRemaining_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The amount of health remaining after each round." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_healthRemaining = { UE4CodeGen_Private::EPropertyClass::Float, "healthRemaining", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, healthRemaining), METADATA_PARAMS(NewProp_healthRemaining_MetaData, ARRAY_COUNT(NewProp_healthRemaining_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_timeRemaining_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The amount of time remaining after each round." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_timeRemaining = { UE4CodeGen_Private::EPropertyClass::Float, "timeRemaining", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, timeRemaining), METADATA_PARAMS(NewProp_timeRemaining_MetaData, ARRAY_COUNT(NewProp_timeRemaining_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_totalScore_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ScoreSystem" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "The total score of the match for the player." },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_totalScore = { UE4CodeGen_Private::EPropertyClass::Int, "totalScore", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FScoreSystem, totalScore), METADATA_PARAMS(NewProp_totalScore_MetaData, ARRAY_COUNT(NewProp_totalScore_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_specialFinish,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_winPerfectGame,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_perfectRound,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numAttacksBlocked,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numTaunts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numSpecialHits,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numHeavyHits,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numHits,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_healthRemaining,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_timeRemaining,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_totalScore,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"ScoreSystem",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FScoreSystem),
				alignof(FScoreSystem),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FScoreSystem_CRC() { return 2769389207U; }
	static FName NAME_AFighterParent_BlockEffectBlueprintEvent = FName(TEXT("BlockEffectBlueprintEvent"));
	void AFighterParent::BlockEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_BlockEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_DashEffectBlueprintEvent = FName(TEXT("DashEffectBlueprintEvent"));
	void AFighterParent::DashEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_DashEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_DeathEffectBlueprintEvent = FName(TEXT("DeathEffectBlueprintEvent"));
	void AFighterParent::DeathEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_DeathEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_FirstAttackEffectBlueprintEvent = FName(TEXT("FirstAttackEffectBlueprintEvent"));
	void AFighterParent::FirstAttackEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_FirstAttackEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_FourthAttackEffectBlueprintEvent = FName(TEXT("FourthAttackEffectBlueprintEvent"));
	void AFighterParent::FourthAttackEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_FourthAttackEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_HighJumpEffectBlueprintEvent = FName(TEXT("HighJumpEffectBlueprintEvent"));
	void AFighterParent::HighJumpEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_HighJumpEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_JumpEffectBlueprintEvent = FName(TEXT("JumpEffectBlueprintEvent"));
	void AFighterParent::JumpEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_JumpEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_LandEffectBlueprintEvent = FName(TEXT("LandEffectBlueprintEvent"));
	void AFighterParent::LandEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_LandEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_SecondAttackEffectBlueprintEvent = FName(TEXT("SecondAttackEffectBlueprintEvent"));
	void AFighterParent::SecondAttackEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_SecondAttackEffectBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_TakeDamageBlueprintEvent = FName(TEXT("TakeDamageBlueprintEvent"));
	void AFighterParent::TakeDamageBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_TakeDamageBlueprintEvent),NULL);
	}
	static FName NAME_AFighterParent_ThirdAttackEffectBlueprintEvent = FName(TEXT("ThirdAttackEffectBlueprintEvent"));
	void AFighterParent::ThirdAttackEffectBlueprintEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFighterParent_ThirdAttackEffectBlueprintEvent),NULL);
	}
	void AFighterParent::StaticRegisterNativesAFighterParent()
	{
		UClass* Class = AFighterParent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "destroy", (Native)&AFighterParent::execdestroy },
			{ "GetCurrentHealth", (Native)&AFighterParent::execGetCurrentHealth },
			{ "GetCurrentStamina", (Native)&AFighterParent::execGetCurrentStamina },
			{ "GetLastPressedKey", (Native)&AFighterParent::execGetLastPressedKey },
			{ "GetTotalHealth", (Native)&AFighterParent::execGetTotalHealth },
			{ "GetTotalStamina", (Native)&AFighterParent::execGetTotalStamina },
			{ "onHit", (Native)&AFighterParent::execonHit },
			{ "ResetHealth", (Native)&AFighterParent::execResetHealth },
			{ "ResetStamina", (Native)&AFighterParent::execResetStamina },
			{ "SetLastPressedKey", (Native)&AFighterParent::execSetLastPressedKey },
			{ "SetStaminaRegen", (Native)&AFighterParent::execSetStaminaRegen },
			{ "spawnHitbox", (Native)&AFighterParent::execspawnHitbox },
			{ "SuperAbility", (Native)&AFighterParent::execSuperAbility },
			{ "takeDamage", (Native)&AFighterParent::exectakeDamage },
			{ "TauntStaminaRegen", (Native)&AFighterParent::execTauntStaminaRegen },
			{ "UpdateCurrentHealth", (Native)&AFighterParent::execUpdateCurrentHealth },
			{ "UpdateCurrentStamina", (Native)&AFighterParent::execUpdateCurrentStamina },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AFighterParent_BlockEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "HealthEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "BlockEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_DashEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "MovementEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "DashEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_DeathEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "HealthEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "DeathEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_destroy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Destroying" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "destroy", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_FirstAttackEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "AttackEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "FirstAttackEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_FourthAttackEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "AttackEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "FourthAttackEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_GetCurrentHealth()
	{
		struct FighterParent_eventGetCurrentHealth_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventGetCurrentHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Accessor function for Current Health" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "GetCurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(FighterParent_eventGetCurrentHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_GetCurrentStamina()
	{
		struct FighterParent_eventGetCurrentStamina_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventGetCurrentStamina_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Accessor function for Current Stamina" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "GetCurrentStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(FighterParent_eventGetCurrentStamina_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_GetLastPressedKey()
	{
		struct FighterParent_eventGetLastPressedKey_Parms
		{
			FKey ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventGetLastPressedKey_Parms, ReturnValue), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "GetLastPressedKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04080401, sizeof(FighterParent_eventGetLastPressedKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_GetTotalHealth()
	{
		struct FighterParent_eventGetTotalHealth_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventGetTotalHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Accessor function for Total Health" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "GetTotalHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(FighterParent_eventGetTotalHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_GetTotalStamina()
	{
		struct FighterParent_eventGetTotalStamina_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventGetTotalStamina_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Accessor function for Total Stamina" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "GetTotalStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(FighterParent_eventGetTotalStamina_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_HighJumpEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "MovementEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "HighJumpEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_JumpEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "MovementEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "JumpEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_LandEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "MovementEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "LandEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_onHit()
	{
		struct FighterParent_eventonHit_Parms
		{
			UPrimitiveComponent* HitComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComponent;
			FVector NormalImpulse;
			FHitResult Hit;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit = { UE4CodeGen_Private::EPropertyClass::Struct, "Hit", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(FighterParent_eventonHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(NewProp_Hit_MetaData, ARRAY_COUNT(NewProp_Hit_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse = { UE4CodeGen_Private::EPropertyClass::Struct, "NormalImpulse", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventonHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventonHit_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OtherComponent_MetaData, ARRAY_COUNT(NewProp_OtherComponent_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventonHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComponent = { UE4CodeGen_Private::EPropertyClass::Object, "HitComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventonHit_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_HitComponent_MetaData, ARRAY_COUNT(NewProp_HitComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Hit,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NormalImpulse,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HitComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Collision" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "onHit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C20401, sizeof(FighterParent_eventonHit_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_ResetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "ResetHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_ResetStamina()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "ResetStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_SecondAttackEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "AttackEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "SecondAttackEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_SetLastPressedKey()
	{
		struct FighterParent_eventSetLastPressedKey_Parms
		{
			FKey inKey;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_inKey = { UE4CodeGen_Private::EPropertyClass::Struct, "inKey", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventSetLastPressedKey_Parms, inKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inKey,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Controls" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "SetLastPressedKey", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04080401, sizeof(FighterParent_eventSetLastPressedKey_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_SetStaminaRegen()
	{
		struct FighterParent_eventSetStaminaRegen_Parms
		{
			bool tf;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_tf_SetBit = [](void* Obj){ ((FighterParent_eventSetStaminaRegen_Parms*)Obj)->tf = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_tf = { UE4CodeGen_Private::EPropertyClass::Bool, "tf", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FighterParent_eventSetStaminaRegen_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_tf_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_tf,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "SetStaminaRegen", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(FighterParent_eventSetStaminaRegen_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_spawnHitbox()
	{
		struct FighterParent_eventspawnHitbox_Parms
		{
			EHITBOX_TYPE type;
			FVector offset;
			FVector dimensions;
			float damage;
			bool visible;
			AHitbox* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(FighterParent_eventspawnHitbox_Parms, ReturnValue), Z_Construct_UClass_AHitbox_NoRegister, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_visible_SetBit = [](void* Obj){ ((FighterParent_eventspawnHitbox_Parms*)Obj)->visible = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_visible = { UE4CodeGen_Private::EPropertyClass::Bool, "visible", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FighterParent_eventspawnHitbox_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_visible_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damage = { UE4CodeGen_Private::EPropertyClass::Float, "damage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventspawnHitbox_Parms, damage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_dimensions = { UE4CodeGen_Private::EPropertyClass::Struct, "dimensions", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventspawnHitbox_Parms, dimensions), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_offset = { UE4CodeGen_Private::EPropertyClass::Struct, "offset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventspawnHitbox_Parms, offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_type = { UE4CodeGen_Private::EPropertyClass::Enum, "type", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventspawnHitbox_Parms, type), Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_type_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_visible,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_damage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dimensions,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_offset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_type,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_type_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Hitboxes" },
				{ "CPP_Default_visible", "true" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "spawnHitbox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04880401, sizeof(FighterParent_eventspawnHitbox_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_SuperAbility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "SuperAbility", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_takeDamage()
	{
		struct FighterParent_eventtakeDamage_Parms
		{
			float damage;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damage = { UE4CodeGen_Private::EPropertyClass::Float, "damage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventtakeDamage_Parms, damage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_damage,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "takeDamage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(FighterParent_eventtakeDamage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_TakeDamageBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Hitboxes" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Creates an event that fires off in blueprints." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "TakeDamageBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_TauntStaminaRegen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Yo Mamma" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "TauntStaminaRegen", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_ThirdAttackEffectBlueprintEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "AttackEffects" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "ThirdAttackEffectBlueprintEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_UpdateCurrentHealth()
	{
		struct FighterParent_eventUpdateCurrentHealth_Parms
		{
			float Health;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health = { UE4CodeGen_Private::EPropertyClass::Float, "Health", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventUpdateCurrentHealth_Parms, Health), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Health,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Updates the Players Current Stamina\n@param Health Amount to change Stamina by(Posivive or Negative)." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "UpdateCurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(FighterParent_eventUpdateCurrentHealth_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AFighterParent_UpdateCurrentStamina()
	{
		struct FighterParent_eventUpdateCurrentStamina_Parms
		{
			float Stamina;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Stamina = { UE4CodeGen_Private::EPropertyClass::Float, "Stamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(FighterParent_eventUpdateCurrentStamina_Parms, Stamina), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Stamina,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Updates the Players Current Stamina\n@param Stamina Amount to change Stamina by(Posivive or Negative)." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AFighterParent, "UpdateCurrentStamina", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(FighterParent_eventUpdateCurrentStamina_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFighterParent_NoRegister()
	{
		return AFighterParent::StaticClass();
	}
	UClass* Z_Construct_UClass_AFighterParent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AFighterParent_BlockEffectBlueprintEvent, "BlockEffectBlueprintEvent" }, // 2661111710
				{ &Z_Construct_UFunction_AFighterParent_DashEffectBlueprintEvent, "DashEffectBlueprintEvent" }, // 2502172776
				{ &Z_Construct_UFunction_AFighterParent_DeathEffectBlueprintEvent, "DeathEffectBlueprintEvent" }, // 1099040792
				{ &Z_Construct_UFunction_AFighterParent_destroy, "destroy" }, // 3201516903
				{ &Z_Construct_UFunction_AFighterParent_FirstAttackEffectBlueprintEvent, "FirstAttackEffectBlueprintEvent" }, // 3454352673
				{ &Z_Construct_UFunction_AFighterParent_FourthAttackEffectBlueprintEvent, "FourthAttackEffectBlueprintEvent" }, // 1407685434
				{ &Z_Construct_UFunction_AFighterParent_GetCurrentHealth, "GetCurrentHealth" }, // 1732373029
				{ &Z_Construct_UFunction_AFighterParent_GetCurrentStamina, "GetCurrentStamina" }, // 949997656
				{ &Z_Construct_UFunction_AFighterParent_GetLastPressedKey, "GetLastPressedKey" }, // 2914889982
				{ &Z_Construct_UFunction_AFighterParent_GetTotalHealth, "GetTotalHealth" }, // 2104257797
				{ &Z_Construct_UFunction_AFighterParent_GetTotalStamina, "GetTotalStamina" }, // 1982847204
				{ &Z_Construct_UFunction_AFighterParent_HighJumpEffectBlueprintEvent, "HighJumpEffectBlueprintEvent" }, // 4024882289
				{ &Z_Construct_UFunction_AFighterParent_JumpEffectBlueprintEvent, "JumpEffectBlueprintEvent" }, // 533106537
				{ &Z_Construct_UFunction_AFighterParent_LandEffectBlueprintEvent, "LandEffectBlueprintEvent" }, // 1554898611
				{ &Z_Construct_UFunction_AFighterParent_onHit, "onHit" }, // 2458034458
				{ &Z_Construct_UFunction_AFighterParent_ResetHealth, "ResetHealth" }, // 3974191029
				{ &Z_Construct_UFunction_AFighterParent_ResetStamina, "ResetStamina" }, // 504431893
				{ &Z_Construct_UFunction_AFighterParent_SecondAttackEffectBlueprintEvent, "SecondAttackEffectBlueprintEvent" }, // 3517483915
				{ &Z_Construct_UFunction_AFighterParent_SetLastPressedKey, "SetLastPressedKey" }, // 1165595317
				{ &Z_Construct_UFunction_AFighterParent_SetStaminaRegen, "SetStaminaRegen" }, // 2562859391
				{ &Z_Construct_UFunction_AFighterParent_spawnHitbox, "spawnHitbox" }, // 3788895502
				{ &Z_Construct_UFunction_AFighterParent_SuperAbility, "SuperAbility" }, // 1863027220
				{ &Z_Construct_UFunction_AFighterParent_takeDamage, "takeDamage" }, // 2454446064
				{ &Z_Construct_UFunction_AFighterParent_TakeDamageBlueprintEvent, "TakeDamageBlueprintEvent" }, // 3313535773
				{ &Z_Construct_UFunction_AFighterParent_TauntStaminaRegen, "TauntStaminaRegen" }, // 4127556477
				{ &Z_Construct_UFunction_AFighterParent_ThirdAttackEffectBlueprintEvent, "ThirdAttackEffectBlueprintEvent" }, // 1504355428
				{ &Z_Construct_UFunction_AFighterParent_UpdateCurrentHealth, "UpdateCurrentHealth" }, // 840592479
				{ &Z_Construct_UFunction_AFighterParent_UpdateCurrentStamina, "UpdateCurrentStamina" }, // 3124294528
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Super80sFighterCharacter.h" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpThreshold_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpThreshold = { UE4CodeGen_Private::EPropertyClass::Float, "JumpThreshold", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, JumpThreshold), METADATA_PARAMS(NewProp_JumpThreshold_MetaData, ARRAY_COUNT(NewProp_JumpThreshold_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CustomShortJumpVelocity_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Demo jump velocity was 1000.0f" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CustomShortJumpVelocity = { UE4CodeGen_Private::EPropertyClass::Float, "CustomShortJumpVelocity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, CustomShortJumpVelocity), METADATA_PARAMS(NewProp_CustomShortJumpVelocity_MetaData, ARRAY_COUNT(NewProp_CustomShortJumpVelocity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CustomHighJumpVelocity_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CustomHighJumpVelocity = { UE4CodeGen_Private::EPropertyClass::Float, "CustomHighJumpVelocity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, CustomHighJumpVelocity), METADATA_PARAMS(NewProp_CustomHighJumpVelocity_MetaData, ARRAY_COUNT(NewProp_CustomHighJumpVelocity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isHoldingJump_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isHoldingJump_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isHoldingJump = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isHoldingJump = { UE4CodeGen_Private::EPropertyClass::Bool, "isHoldingJump", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isHoldingJump_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isHoldingJump_MetaData, ARRAY_COUNT(NewProp_isHoldingJump_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isCrouching_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Movement Variables" },
			};
#endif
			auto NewProp_isCrouching_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isCrouching = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isCrouching = { UE4CodeGen_Private::EPropertyClass::Bool, "isCrouching", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isCrouching_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isCrouching_MetaData, ARRAY_COUNT(NewProp_isCrouching_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isBlocking_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isBlocking_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isBlocking = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isBlocking = { UE4CodeGen_Private::EPropertyClass::Bool, "isBlocking", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isBlocking_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isBlocking_MetaData, ARRAY_COUNT(NewProp_isBlocking_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isAttackingTaunt_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isAttackingTaunt_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isAttackingTaunt = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isAttackingTaunt = { UE4CodeGen_Private::EPropertyClass::Bool, "isAttackingTaunt", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isAttackingTaunt_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isAttackingTaunt_MetaData, ARRAY_COUNT(NewProp_isAttackingTaunt_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isAttacking3_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isAttacking3_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isAttacking3 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isAttacking3 = { UE4CodeGen_Private::EPropertyClass::Bool, "isAttacking3", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isAttacking3_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isAttacking3_MetaData, ARRAY_COUNT(NewProp_isAttacking3_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isAttacking2_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isAttacking2_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isAttacking2 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isAttacking2 = { UE4CodeGen_Private::EPropertyClass::Bool, "isAttacking2", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isAttacking2_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isAttacking2_MetaData, ARRAY_COUNT(NewProp_isAttacking2_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isAttacking1_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_isAttacking1_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isAttacking1 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isAttacking1 = { UE4CodeGen_Private::EPropertyClass::Bool, "isAttacking1", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isAttacking1_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isAttacking1_MetaData, ARRAY_COUNT(NewProp_isAttacking1_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isAttacking0_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Attacking variables" },
			};
#endif
			auto NewProp_isAttacking0_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->isAttacking0 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isAttacking0 = { UE4CodeGen_Private::EPropertyClass::Bool, "isAttacking0", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isAttacking0_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isAttacking0_MetaData, ARRAY_COUNT(NewProp_isAttacking0_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_comboCounter_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_comboCounter = { UE4CodeGen_Private::EPropertyClass::Int, "comboCounter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, comboCounter), METADATA_PARAMS(NewProp_comboCounter_MetaData, ARRAY_COUNT(NewProp_comboCounter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_grounded_MetaData[] = {
				{ "Category", "Physics" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "dave cranes private physics variables, if they're screwy, its entirely his fault" },
			};
#endif
			auto NewProp_grounded_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->grounded = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_grounded = { UE4CodeGen_Private::EPropertyClass::Bool, "grounded", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_grounded_SetBit)>::SetBit, METADATA_PARAMS(NewProp_grounded_MetaData, ARRAY_COUNT(NewProp_grounded_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_initial3Counter_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_initial3Counter = { UE4CodeGen_Private::EPropertyClass::Int, "initial3Counter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, initial3Counter), METADATA_PARAMS(NewProp_initial3Counter_MetaData, ARRAY_COUNT(NewProp_initial3Counter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_initial2Counter_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_initial2Counter = { UE4CodeGen_Private::EPropertyClass::Int, "initial2Counter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, initial2Counter), METADATA_PARAMS(NewProp_initial2Counter_MetaData, ARRAY_COUNT(NewProp_initial2Counter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_initialCounter_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_initialCounter = { UE4CodeGen_Private::EPropertyClass::Int, "initialCounter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, initialCounter), METADATA_PARAMS(NewProp_initialCounter_MetaData, ARRAY_COUNT(NewProp_initialCounter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_initialSelector_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_initialSelector = { UE4CodeGen_Private::EPropertyClass::Int, "initialSelector", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, initialSelector), METADATA_PARAMS(NewProp_initialSelector_MetaData, ARRAY_COUNT(NewProp_initialSelector_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsFacingRight_MetaData[] = {
				{ "Category", "Orientation" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			auto NewProp_IsFacingRight_SetBit = [](void* Obj){ ((AFighterParent*)Obj)->IsFacingRight = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsFacingRight = { UE4CodeGen_Private::EPropertyClass::Bool, "IsFacingRight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AFighterParent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_IsFacingRight_SetBit)>::SetBit, METADATA_PARAMS(NewProp_IsFacingRight_MetaData, ARRAY_COUNT(NewProp_IsFacingRight_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitboxes_MetaData[] = {
				{ "Category", "Hitboxes" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_hitboxes = { UE4CodeGen_Private::EPropertyClass::Array, "hitboxes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000020001, 1, nullptr, STRUCT_OFFSET(AFighterParent, hitboxes), METADATA_PARAMS(NewProp_hitboxes_MetaData, ARRAY_COUNT(NewProp_hitboxes_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_hitboxes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "hitboxes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000020000, 1, nullptr, 0, Z_Construct_UClass_AHitbox_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Player Current Health" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AFighterParent, CurrentHealth), METADATA_PARAMS(NewProp_CurrentHealth_MetaData, ARRAY_COUNT(NewProp_CurrentHealth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TotalHealth_MetaData[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Player Total Health" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TotalHealth = { UE4CodeGen_Private::EPropertyClass::Float, "TotalHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AFighterParent, TotalHealth), METADATA_PARAMS(NewProp_TotalHealth_MetaData, ARRAY_COUNT(NewProp_TotalHealth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentStamina_MetaData[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Player Current Stamina" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentStamina = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentStamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AFighterParent, CurrentStamina), METADATA_PARAMS(NewProp_CurrentStamina_MetaData, ARRAY_COUNT(NewProp_CurrentStamina_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TotalStamina_MetaData[] = {
				{ "Category", "Stats" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Player Total Stamina" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TotalStamina = { UE4CodeGen_Private::EPropertyClass::Float, "TotalStamina", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000001, 1, nullptr, STRUCT_OFFSET(AFighterParent, TotalStamina), METADATA_PARAMS(NewProp_TotalStamina_MetaData, ARRAY_COUNT(NewProp_TotalStamina_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_playerScore_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "FighterParent" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_playerScore = { UE4CodeGen_Private::EPropertyClass::Struct, "playerScore", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AFighterParent, playerScore), Z_Construct_UScriptStruct_FScoreSystem, METADATA_PARAMS(NewProp_playerScore_MetaData, ARRAY_COUNT(NewProp_playerScore_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_tempHitbox_MetaData[] = {
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_tempHitbox = { UE4CodeGen_Private::EPropertyClass::Object, "tempHitbox", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000000, 1, nullptr, STRUCT_OFFSET(AFighterParent, tempHitbox), Z_Construct_UClass_AHitbox_NoRegister, METADATA_PARAMS(NewProp_tempHitbox_MetaData, ARRAY_COUNT(NewProp_tempHitbox_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Camera boom positioning the camera beside the character" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFighterParent, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_CameraBoom_MetaData, ARRAY_COUNT(NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Super80sFighterCharacter.h" },
				{ "ToolTip", "Side view camera" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SideViewCameraComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AFighterParent, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_SideViewCameraComponent_MetaData, ARRAY_COUNT(NewProp_SideViewCameraComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_JumpThreshold,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CustomShortJumpVelocity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CustomHighJumpVelocity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isHoldingJump,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isCrouching,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isBlocking,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isAttackingTaunt,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isAttacking3,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isAttacking2,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isAttacking1,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isAttacking0,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_comboCounter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_grounded,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_initial3Counter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_initial2Counter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_initialCounter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_initialSelector,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_IsFacingRight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxes,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxes_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TotalHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentStamina,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TotalStamina,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_playerScore,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_tempHitbox,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraBoom,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SideViewCameraComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AFighterParent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AFighterParent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFighterParent, 3995048379);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFighterParent(Z_Construct_UClass_AFighterParent, &AFighterParent::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("AFighterParent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFighterParent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
