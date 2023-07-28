// Copyright 2023 Xiao Gang. All Rights Reserved.



#include "XGHelperAsyncAction.h"


UXGBlueprintAsyncAction* UXGBlueprintAsyncAction::AsyncDelay(UObject* WorldContextObject, float Delay)
{
	UXGBlueprintAsyncAction* Node = NewObject<UXGBlueprintAsyncAction>();
	//构建定时器
	FTimerHandle Handle1;
	FTimerHandle Handle2;
	if (WorldContextObject)
	{
		WorldContextObject->GetWorld()->GetTimerManager().SetTimer(Handle1, FTimerDelegate::CreateUObject(Node, &UXGBlueprintAsyncAction::TimeoutCallbackSuccess), Delay, false);
		WorldContextObject->GetWorld()->GetTimerManager().SetTimer(Handle2, FTimerDelegate::CreateUObject(Node, &UXGBlueprintAsyncAction::TimeoutCallbackSuccessFail), Delay + 1, false);
	}

	return Node;
}

void UXGBlueprintAsyncAction::TimeoutCallbackSuccess()
{
	if (OnSuccess.IsBound())
	{
		OnSuccess.Broadcast(10);
	}
}

void UXGBlueprintAsyncAction::TimeoutCallbackSuccessFail()
{
	if (OnFail.IsBound())
	{
		OnFail.Broadcast(99);
	}
}

