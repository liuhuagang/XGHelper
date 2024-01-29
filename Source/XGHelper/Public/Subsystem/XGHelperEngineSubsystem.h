// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "XGHelperEngineSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class XGHELPER_API UXGHelperEngineSubsystem : public UEngineSubsystem,public FTickableGameObject
{
	GENERATED_BODY()


#pragma region InitSubsystem

public:

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection)override;
	virtual void Deinitialize()override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override {return !IsTemplate();}
	virtual TStatId GetStatId() const override{ RETURN_QUICK_DECLARE_CYCLE_STAT(UXGHelperSubsystem, STATGROUP_Tickables); }

#pragma endregion InitSubsystem



	
};
