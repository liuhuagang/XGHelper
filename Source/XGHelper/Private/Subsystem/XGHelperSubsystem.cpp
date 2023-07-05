// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperSubsystem.h"


#pragma region InitSubsystem
bool UXGHelperSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UXGHelperSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void UXGHelperSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UXGHelperSubsystem::Tick(float DeltaTime)
{

}

bool UXGHelperSubsystem::IsTickable() const
{
	 return !IsTemplate(); 
}

TStatId UXGHelperSubsystem::GetStatId() const
{
 RETURN_QUICK_DECLARE_CYCLE_STAT(UXGHelperSubsystem, STATGROUP_Tickables);
}



#pragma endregion InitSubsystem
