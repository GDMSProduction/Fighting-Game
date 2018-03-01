// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MySuper80sFighterAIBehavior.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySuper80sFighterAIBehavior() {}
// Cross Module References
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AFighterParent();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Do();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Dont();
// End Cross Module References
	void AMySuper80sFighterAIBehavior::StaticRegisterNativesAMySuper80sFighterAIBehavior()
	{
		UClass* Class = AMySuper80sFighterAIBehavior::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Do", (Native)&AMySuper80sFighterAIBehavior::execDo },
			{ "Dont", (Native)&AMySuper80sFighterAIBehavior::execDont },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Do()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Do" },
				{ "ModuleRelativePath", "MySuper80sFighterAIBehavior.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AMySuper80sFighterAIBehavior, "Do", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Dont()
	{
		struct MySuper80sFighterAIBehavior_eventDont_Parms
		{
			int32 blarb;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_blarb = { UE4CodeGen_Private::EPropertyClass::Int, "blarb", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MySuper80sFighterAIBehavior_eventDont_Parms, blarb), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_blarb,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Do" },
				{ "ModuleRelativePath", "MySuper80sFighterAIBehavior.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AMySuper80sFighterAIBehavior, "Dont", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(MySuper80sFighterAIBehavior_eventDont_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior_NoRegister()
	{
		return AMySuper80sFighterAIBehavior::StaticClass();
	}
	UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AFighterParent,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Do, "Do" }, // 764450987
				{ &Z_Construct_UFunction_AMySuper80sFighterAIBehavior_Dont, "Dont" }, // 1279585917
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "MySuper80sFighterAIBehavior.h" },
				{ "ModuleRelativePath", "MySuper80sFighterAIBehavior.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMySuper80sFighterAIBehavior>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMySuper80sFighterAIBehavior::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMySuper80sFighterAIBehavior, 683924826);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMySuper80sFighterAIBehavior(Z_Construct_UClass_AMySuper80sFighterAIBehavior, &AMySuper80sFighterAIBehavior::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("AMySuper80sFighterAIBehavior"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMySuper80sFighterAIBehavior);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
