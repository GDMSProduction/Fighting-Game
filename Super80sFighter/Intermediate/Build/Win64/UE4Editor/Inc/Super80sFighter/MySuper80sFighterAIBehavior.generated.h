// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUPER80SFIGHTER_MySuper80sFighterAIBehavior_generated_h
#error "MySuper80sFighterAIBehavior.generated.h already included, missing '#pragma once' in MySuper80sFighterAIBehavior.h"
#endif
#define SUPER80SFIGHTER_MySuper80sFighterAIBehavior_generated_h

#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDont) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_blarb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Dont(Z_Param_blarb); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Do(); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDont) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_blarb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Dont(Z_Param_blarb); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Do(); \
		P_NATIVE_END; \
	}


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMySuper80sFighterAIBehavior(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior(); \
public: \
	DECLARE_CLASS(AMySuper80sFighterAIBehavior, AFighterParent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AMySuper80sFighterAIBehavior) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAMySuper80sFighterAIBehavior(); \
	friend SUPER80SFIGHTER_API class UClass* Z_Construct_UClass_AMySuper80sFighterAIBehavior(); \
public: \
	DECLARE_CLASS(AMySuper80sFighterAIBehavior, AFighterParent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Super80sFighter"), NO_API) \
	DECLARE_SERIALIZER(AMySuper80sFighterAIBehavior) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMySuper80sFighterAIBehavior(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMySuper80sFighterAIBehavior) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMySuper80sFighterAIBehavior); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMySuper80sFighterAIBehavior); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMySuper80sFighterAIBehavior(AMySuper80sFighterAIBehavior&&); \
	NO_API AMySuper80sFighterAIBehavior(const AMySuper80sFighterAIBehavior&); \
public:


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMySuper80sFighterAIBehavior() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMySuper80sFighterAIBehavior(AMySuper80sFighterAIBehavior&&); \
	NO_API AMySuper80sFighterAIBehavior(const AMySuper80sFighterAIBehavior&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMySuper80sFighterAIBehavior); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMySuper80sFighterAIBehavior); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMySuper80sFighterAIBehavior)


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_PRIVATE_PROPERTY_OFFSET
#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_7_PROLOG
#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_RPC_WRAPPERS \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_INCLASS \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_PRIVATE_PROPERTY_OFFSET \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_INCLASS_NO_PURE_DECLS \
	Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Super80sFighter_Source_Super80sFighter_MySuper80sFighterAIBehavior_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
