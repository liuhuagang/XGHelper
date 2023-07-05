// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XGHelperUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class XGHELPER_API UXGHelperUserWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:

	virtual void NativeOnInitialized();
	virtual void NativePreConstruct();
	virtual void NativeConstruct();
	virtual void NativeDestruct();
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

};
