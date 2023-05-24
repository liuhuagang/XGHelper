// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "XGHelperBPLibrary.generated.h"


UCLASS()
class UXGHelperBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "XGHelper sample test testing"), Category = "XGHelperTesting")
	static float XGHelperSampleFunction(float Param);
};
