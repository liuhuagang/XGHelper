// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XGHelperMediaPixelProcess.generated.h"

class UTextureRenderTarget2D;
UCLASS()
class AXGHelperMediaPixelProcess : public AActor
{
	GENERATED_BODY()

public:

	AXGHelperMediaPixelProcess();


public:
	



public:
	UFUNCTION(BlueprintCallable)
	bool ProcessData(UTextureRenderTarget2D* TextureRenderTarget2D);

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

};
