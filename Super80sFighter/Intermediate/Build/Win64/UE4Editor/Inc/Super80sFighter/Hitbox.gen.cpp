// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Hitbox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHitbox() {}
// Cross Module References
	SUPER80SFIGHTER_API UEnum* Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE();
	UPackage* Z_Construct_UPackage__Script_Super80sFighter();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AHitbox_NoRegister();
	SUPER80SFIGHTER_API UClass* Z_Construct_UClass_AHitbox();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SUPER80SFIGHTER_API UFunction* Z_Construct_UFunction_AHitbox_OnHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static UEnum* EHITBOX_TYPE_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE, Z_Construct_UPackage__Script_Super80sFighter(), TEXT("EHITBOX_TYPE"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EHITBOX_TYPE(EHITBOX_TYPE_StaticEnum, TEXT("/Script/Super80sFighter"), TEXT("EHITBOX_TYPE"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE_CRC() { return 3343504288U; }
	UEnum* Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Super80sFighter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EHITBOX_TYPE"), 0, Get_Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EHITBOX_TYPE::VE_HITBOX_STRIKE", (int64)EHITBOX_TYPE::VE_HITBOX_STRIKE },
				{ "EHITBOX_TYPE::VE_HITBOX_PROJECTILE", (int64)EHITBOX_TYPE::VE_HITBOX_PROJECTILE },
				{ "EHITBOX_TYPE::VE_HITBOX_PROXIMITY", (int64)EHITBOX_TYPE::VE_HITBOX_PROXIMITY },
				{ "EHITBOX_TYPE::VE_HITBOX_THROW", (int64)EHITBOX_TYPE::VE_HITBOX_THROW },
				{ "EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX", (int64)EHITBOX_TYPE::VE_HITBOX_GET_PAINBOX },
				{ "EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX", (int64)EHITBOX_TYPE::VE_HITBOX_GET_THROWBOX },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "enum for hitbox types" },
				{ "VE_HITBOX_GET_PAINBOX.DisplayName", "P_Hitbox" },
				{ "VE_HITBOX_GET_PAINBOX.ToolTip", "hitbox that shows the area that the grab attack is affecting" },
				{ "VE_HITBOX_GET_THROWBOX.DisplayName", "P_Throwbox" },
				{ "VE_HITBOX_GET_THROWBOX.ToolTip", "the area of the player that can be hit" },
				{ "VE_HITBOX_PROJECTILE.DisplayName", "Projectile" },
				{ "VE_HITBOX_PROJECTILE.ToolTip", "hitbox of a strike attack" },
				{ "VE_HITBOX_PROXIMITY.DisplayName", "Proximity" },
				{ "VE_HITBOX_PROXIMITY.ToolTip", "hitbox of a projectile attack" },
				{ "VE_HITBOX_STRIKE.DisplayName", "Strike" },
				{ "VE_HITBOX_THROW.DisplayName", "Throw" },
				{ "VE_HITBOX_THROW.ToolTip", "hitbox that protrudes from an attack to determine whether the player should block it" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Super80sFighter,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EHITBOX_TYPE",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EHITBOX_TYPE",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AHitbox::StaticRegisterNativesAHitbox()
	{
		UClass* Class = AHitbox::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHit", (Native)&AHitbox::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AHitbox_OnHit()
	{
		struct Hitbox_eventOnHit_Parms
		{
			UPrimitiveComponent* thisHitbox;
			AActor* otherActor;
			UPrimitiveComponent* otherComp;
			int32 otherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SweepResult", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(Hitbox_eventOnHit_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(NewProp_SweepResult_MetaData, ARRAY_COUNT(NewProp_SweepResult_MetaData)) };
			auto NewProp_bFromSweep_SetBit = [](void* Obj){ ((Hitbox_eventOnHit_Parms*)Obj)->bFromSweep = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep = { UE4CodeGen_Private::EPropertyClass::Bool, "bFromSweep", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Hitbox_eventOnHit_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bFromSweep_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_otherBodyIndex = { UE4CodeGen_Private::EPropertyClass::Int, "otherBodyIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Hitbox_eventOnHit_Parms, otherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_otherComp_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_otherComp = { UE4CodeGen_Private::EPropertyClass::Object, "otherComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(Hitbox_eventOnHit_Parms, otherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_otherComp_MetaData, ARRAY_COUNT(NewProp_otherComp_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_otherActor = { UE4CodeGen_Private::EPropertyClass::Object, "otherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Hitbox_eventOnHit_Parms, otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_thisHitbox_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_thisHitbox = { UE4CodeGen_Private::EPropertyClass::Object, "thisHitbox", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(Hitbox_eventOnHit_Parms, thisHitbox), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_thisHitbox_MetaData, ARRAY_COUNT(NewProp_thisHitbox_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SweepResult,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bFromSweep,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_otherBodyIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_otherComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_otherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_thisHitbox,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Hitboxes" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "hitbox collision function" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AHitbox, "OnHit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(Hitbox_eventOnHit_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHitbox_NoRegister()
	{
		return AHitbox::StaticClass();
	}
	UClass* Z_Construct_UClass_AHitbox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_Super80sFighter,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AHitbox_OnHit, "OnHit" }, // 1177536089
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Hitbox.h" },
				{ "ModuleRelativePath", "Hitbox.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_damage_MetaData[] = {
				{ "Category", "Damage" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "how much damage the attack will deal when the enemy is hit" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damage = { UE4CodeGen_Private::EPropertyClass::Float, "damage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AHitbox, damage), METADATA_PARAMS(NewProp_damage_MetaData, ARRAY_COUNT(NewProp_damage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitboxMaterial_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "material of the hibox object" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_hitboxMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "hitboxMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AHitbox, hitboxMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(NewProp_hitboxMaterial_MetaData, ARRAY_COUNT(NewProp_hitboxMaterial_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitbox_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "a mesh to show the hitbox" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_hitbox = { UE4CodeGen_Private::EPropertyClass::Object, "hitbox", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AHitbox, hitbox), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_hitbox_MetaData, ARRAY_COUNT(NewProp_hitbox_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_color_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "color of the hitbox" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_color = { UE4CodeGen_Private::EPropertyClass::Struct, "color", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(AHitbox, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(NewProp_color_MetaData, ARRAY_COUNT(NewProp_color_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_showHitbox_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "whether or not to display the hitbox to the user (off by default)" },
			};
#endif
			auto NewProp_showHitbox_SetBit = [](void* Obj){ ((AHitbox*)Obj)->showHitbox = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_showHitbox = { UE4CodeGen_Private::EPropertyClass::Bool, "showHitbox", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AHitbox), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_showHitbox_SetBit)>::SetBit, METADATA_PARAMS(NewProp_showHitbox_MetaData, ARRAY_COUNT(NewProp_showHitbox_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitboxPosition_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "position of the hitbox relative to the character's center" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_hitboxPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "hitboxPosition", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AHitbox, hitboxPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_hitboxPosition_MetaData, ARRAY_COUNT(NewProp_hitboxPosition_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_hitboxType_MetaData[] = {
				{ "Category", "Hitbox Details" },
				{ "ModuleRelativePath", "Hitbox.h" },
				{ "ToolTip", "the type of hitbox this is" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_hitboxType = { UE4CodeGen_Private::EPropertyClass::Enum, "hitboxType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AHitbox, hitboxType), Z_Construct_UEnum_Super80sFighter_EHITBOX_TYPE, METADATA_PARAMS(NewProp_hitboxType_MetaData, ARRAY_COUNT(NewProp_hitboxType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_hitboxType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_damage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxMaterial,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitbox,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_color,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_showHitbox,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxPosition,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_hitboxType_Underlying,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AHitbox>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AHitbox::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(AHitbox, 1796559692);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHitbox(Z_Construct_UClass_AHitbox, &AHitbox::StaticClass, TEXT("/Script/Super80sFighter"), TEXT("AHitbox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHitbox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
