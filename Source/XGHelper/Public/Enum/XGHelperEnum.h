// Copyright 2023 Xiao Gang. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "XGHelperEnum.generated.h"

UENUM()
namespace EXGHelperEnumOldStyle
{
	enum Type
	{
		XG_TestEnum,
		XG_EnumTest,
	};
}

UENUM(BlueprintType)
enum class EXGEnumGeneralStyle : uint8
{
	XG_None 	UMETA(DisplayName = "None"),
	XG_TestEnum 	UMETA(DisplayName = "TestEnum"),
	XG_EnumTest		UMETA(DisplayName = "XG_EnumTest")
};