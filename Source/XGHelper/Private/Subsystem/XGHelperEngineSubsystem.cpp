// Copyright 2023 Xiao Gang. All Rights Reserved.


#include "XGHelperEngineSubsystem.h"


#pragma region InitSubsystem
bool UXGHelperEngineSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

void UXGHelperEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UXGHelperEngineSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UXGHelperEngineSubsystem::Tick(float DeltaTime)
{

}
#pragma endregion InitSubsystem
