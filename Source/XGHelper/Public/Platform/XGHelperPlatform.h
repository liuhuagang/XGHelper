// Copyright 2023 Xiao Gang. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "XGHelperPlatform.generated.h"

UCLASS()
class UXGHelperPlatformBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "XGHelper OpenFileDialog", Keywords = "XGHelper Open File Dialog"), Category = "XGHelper|Platform")
		static void XGHelperOpenFileDialog();


		static void XGHelperFileOperate();



};
