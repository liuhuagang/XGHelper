// Copyright 2023 Xiao Gang. All Rights Reserved.

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "XGHelperAsyncAction.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintAsyncNodePinResult, int32, Result);
/**
 *
 */
UCLASS()
class  UXGBlueprintAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FBlueprintAsyncNodePinResult OnSuccess;
	UPROPERTY(BlueprintAssignable)
		FBlueprintAsyncNodePinResult OnFail;


	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", Delay = "0.5"))
		static UXGBlueprintAsyncAction* AsyncDelay(UObject* WorldContextObject, float Delay);

protected:
	void TimeoutCallbackSuccess();
	void TimeoutCallbackSuccessFail();
};
