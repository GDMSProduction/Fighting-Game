// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ThugClass.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThugClass() {}
// Cross Module References
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AThugClass_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AThugClass();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AFighterParent();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
// End Cross Module References
	void AThugClass::StaticRegisterNativesAThugClass()
	{
	}
	UClass* Z_Construct_UClass_AThugClass_NoRegister()
	{
		return AThugClass::StaticClass();
	}
	UClass* Z_Construct_UClass_AThugClass()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AFighterParent,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "ThugClass.h" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_movesetNumber_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
				{ "ToolTip", "The randomly chosen moveset." },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_movesetNumber = { UE4CodeGen_Private::EPropertyClass::Int, "movesetNumber", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AThugClass, movesetNumber), METADATA_PARAMS(NewProp_movesetNumber_MetaData, ARRAY_COUNT(NewProp_movesetNumber_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isCrouched_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isCrouched_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isCrouched = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isCrouched = { UE4CodeGen_Private::EPropertyClass::Bool, "isCrouched", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isCrouched_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isCrouched_MetaData, ARRAY_COUNT(NewProp_isCrouched_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove8_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove8_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove8 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove8 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove8", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove8_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove8_MetaData, ARRAY_COUNT(NewProp_isMove8_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove7_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove7_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove7 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove7 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove7", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove7_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove7_MetaData, ARRAY_COUNT(NewProp_isMove7_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove6_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove6_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove6 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove6 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove6", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove6_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove6_MetaData, ARRAY_COUNT(NewProp_isMove6_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove5_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove5_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove5 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove5 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove5", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove5_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove5_MetaData, ARRAY_COUNT(NewProp_isMove5_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove4_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove4_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove4 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove4 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove4", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove4_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove4_MetaData, ARRAY_COUNT(NewProp_isMove4_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove3_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove3_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove3 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove3 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove3", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove3_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove3_MetaData, ARRAY_COUNT(NewProp_isMove3_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove2_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove2_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove2 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove2 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove2", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove2_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove2_MetaData, ARRAY_COUNT(NewProp_isMove2_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove1_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
			};
#endif
			auto NewProp_isMove1_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove1 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove1 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove1", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove1_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove1_MetaData, ARRAY_COUNT(NewProp_isMove1_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isMove0_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "ThugClass" },
				{ "ModuleRelativePath", "ThugClass.h" },
				{ "ToolTip", "The attack/movement statuses." },
			};
#endif
			auto NewProp_isMove0_SetBit = [](void* Obj){ ((AThugClass*)Obj)->isMove0 = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isMove0 = { UE4CodeGen_Private::EPropertyClass::Bool, "isMove0", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AThugClass), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isMove0_SetBit)>::SetBit, METADATA_PARAMS(NewProp_isMove0_MetaData, ARRAY_COUNT(NewProp_isMove0_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_movesetNumber,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isCrouched,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove8,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove7,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove6,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove5,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove4,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove3,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove2,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove1,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isMove0,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AThugClass>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AThugClass::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(AThugClass, 2168409455);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AThugClass(Z_Construct_UClass_AThugClass, &AThugClass::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("AThugClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThugClass);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
