// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/StreamableManager.h"
#include "XGStreamableManagerSubsystem.generated.h"



/**
 * 主要演示一下异步加载资源的流程
 * 参考文档:
 * https://docs.unrealengine.com/5.2/zh-CN/asynchronous-asset-loading-in-unreal-engine/
 */


/**
 *
 */
UCLASS()
class XGHELPER_API UXGStreamableManagerSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{

	GENERATED_BODY()


#pragma region InitSubsystem

public:

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection)override;
	virtual void Deinitialize()override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

#pragma endregion InitSubsystem

public:
	
	UFUNCTION(BlueprintCallable,meta=(DisplayName="CollectItemsToAsyncLoad",Keywords="Async Load"), Category = "XGHelper|SreamableManager")
	void GrantItems(TArray<TSoftObjectPtr<UObject>> ItemList);

protected:

	void  GrantItemsDeferred();


private:
	TArray<TSoftObjectPtr<UObject>> ItemList;
	TSharedPtr<FStreamableManager> XGStreamable;


	UPROPERTY()
	TArray<UObject*> GrantedItems;

	TSharedPtr<FStreamableHandle>   XGStreamableHandle;
};
