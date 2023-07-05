// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "XGHelperSubsystem.generated.h"

/**
 *
 */
UCLASS()
class XGHELPER_API UXGHelperSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
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






};
