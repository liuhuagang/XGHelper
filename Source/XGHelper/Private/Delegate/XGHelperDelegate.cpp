// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperDelegate.h"





void UXGHelperDelegateObject::ExectuteBind()
{
	FString Str = TEXT("BindMethod");
	XGHelperDelegate.BindUObject(this,&UXGHelperDelegateObject::BindMethod, Str);
}

void UXGHelperDelegateObject::ExectuteDelegate()
{
	XGHelperDelegate.ExecuteIfBound();
}

void UXGHelperDelegateObject::BindMethod(FString InStr)
{

}

void UXGHelperMulitcastDelegateObject::ExectuteAdd()
{
	FString Str = TEXT("AddMethod");
	XGHelperDelegate.AddUObject(this,&UXGHelperMulitcastDelegateObject::AddMethod,Str);
}

void UXGHelperMulitcastDelegateObject::ExectuteDelegate()
{
	XGHelperDelegate.Broadcast();
}

void UXGHelperMulitcastDelegateObject::AddMethod(FString InStr)
{

}
