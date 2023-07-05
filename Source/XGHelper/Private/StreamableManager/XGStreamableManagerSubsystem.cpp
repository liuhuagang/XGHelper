// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGStreamableManagerSubsystem.h"


#pragma region InitSubsystem
bool UXGStreamableManagerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UXGStreamableManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	XGStreamable = MakeShared<FStreamableManager>();
}

void UXGStreamableManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UXGStreamableManagerSubsystem::Tick(float DeltaTime)
{
	if (0)
	{

		if (XGStreamableHandle.IsValid())
		{


			if (XGStreamableHandle->IsLoadingInProgress())
			{
				UE_LOG(LogTemp, Warning, TEXT("%s Loading"), *FString(__FUNCTION__));

			}
		}
	}
}

bool UXGStreamableManagerSubsystem::IsTickable() const
{
	return !IsTemplate();
}

TStatId UXGStreamableManagerSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UXGStreamableManagerSubsystem, STATGROUP_Tickables);
}



void UXGStreamableManagerSubsystem::GrantItems(TArray<TSoftObjectPtr<UObject>> InItemList)
{
	TArray<FSoftObjectPath> ItemsToStream;
	ItemList.Empty();


	for (int32 i = 0; i < InItemList.Num(); ++i)
	{
		ItemList.Add(InItemList[i]);
		ItemsToStream.AddUnique(InItemList[i].ToSoftObjectPath());



	}
	XGStreamableHandle = XGStreamable->RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &UXGStreamableManagerSubsystem::GrantItemsDeferred));


}

void UXGStreamableManagerSubsystem::GrantItemsDeferred()
{
	for (int32 i = 0; i < ItemList.Num(); ++i)
	{
		UObject* ItemData = ItemList[i].Get();
		if (ItemData)
		{
			GrantedItems.Add(ItemData);
		}
	}

}

#pragma endregion InitSubsystem
