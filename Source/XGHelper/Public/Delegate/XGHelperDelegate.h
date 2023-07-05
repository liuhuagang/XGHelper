// Copyright 2023 Xiao Gang. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "XGHelperDelegate.generated.h"


DECLARE_DELEGATE(FXGHelperDelegate);
DECLARE_MULTICAST_DELEGATE(FXGHelperMulticastDelegate);


UCLASS()
class UXGHelperDelegateObject :public UObject
{
	GENERATED_BODY()


public:

	void ExectuteBind();
	void ExectuteDelegate();
protected:
	void BindMethod(FString InStr);



protected:
	FXGHelperDelegate XGHelperDelegate;

};


UCLASS()
class UXGHelperMulitcastDelegateObject :public UObject
{
	GENERATED_BODY()


public:

	void ExectuteAdd();
	void ExectuteDelegate();
protected:
	void AddMethod(FString InStr);



protected:
	FXGHelperMulticastDelegate XGHelperDelegate;

};



