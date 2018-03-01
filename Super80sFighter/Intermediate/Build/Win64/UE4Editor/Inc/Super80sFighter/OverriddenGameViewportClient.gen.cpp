// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "OverriddenGameViewportClient.h"
#include "Classes/Engine/Engine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverriddenGameViewportClient() {}
// Cross Module References
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_UOverriddenGameViewportClient_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_UOverriddenGameViewportClient();
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
// End Cross Module References
	void UOverriddenGameViewportClient::StaticRegisterNativesUOverriddenGameViewportClient()
	{
	}
	UClass* Z_Construct_UClass_UOverriddenGameViewportClient_NoRegister()
	{
		return UOverriddenGameViewportClient::StaticClass();
	}
	UClass* Z_Construct_UClass_UOverriddenGameViewportClient()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "OverriddenGameViewportClient.h" },
				{ "ModuleRelativePath", "OverriddenGameViewportClient.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UOverriddenGameViewportClient>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UOverriddenGameViewportClient::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100088u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(UOverriddenGameViewportClient, 26369233);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOverriddenGameViewportClient(Z_Construct_UClass_UOverriddenGameViewportClient, &UOverriddenGameViewportClient::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("UOverriddenGameViewportClient"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOverriddenGameViewportClient);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
