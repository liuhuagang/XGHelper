// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperGameInstanceSubsystem.h"


#pragma region InitSubsystem
bool UXGHelperGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UXGHelperGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void UXGHelperGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UXGHelperGameInstanceSubsystem::Tick(float DeltaTime)
{

}

bool UXGHelperGameInstanceSubsystem::IsTickable() const
{
	return !IsTemplate();
}

TStatId UXGHelperGameInstanceSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UXGHelperGameInstanceSubsystem, STATGROUP_Tickables);
}



#pragma endregion InitSubsystem
