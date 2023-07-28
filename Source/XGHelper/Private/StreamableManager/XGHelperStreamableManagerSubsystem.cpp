// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperStreamableManagerSubsystem.h"


#pragma region InitSubsystem
bool UXGHelperStreamableManagerSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UXGHelperStreamableManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	XGStreamable = MakeShared<FStreamableManager>();
}

void UXGHelperStreamableManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UXGHelperStreamableManagerSubsystem::Tick(float DeltaTime)
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

bool UXGHelperStreamableManagerSubsystem::IsTickable() const
{
	return !IsTemplate();
}

TStatId UXGHelperStreamableManagerSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UXGHelperStreamableManagerSubsystem, STATGROUP_Tickables);
}



void UXGHelperStreamableManagerSubsystem::GrantItems(TArray<TSoftObjectPtr<UObject>> InItemList)
{
	TArray<FSoftObjectPath> ItemsToStream;
	ItemList.Empty();


	for (int32 i = 0; i < InItemList.Num(); ++i)
	{
		ItemList.Add(InItemList[i]);
		ItemsToStream.AddUnique(InItemList[i].ToSoftObjectPath());



	}
	XGStreamableHandle = XGStreamable->RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &UXGHelperStreamableManagerSubsystem::GrantItemsDeferred));


}

void UXGHelperStreamableManagerSubsystem::GrantItemsDeferred()
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
