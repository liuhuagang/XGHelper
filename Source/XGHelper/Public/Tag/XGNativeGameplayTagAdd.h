// Copyright 2023 Xiao Gang. All Rights Reserved.
#pragma once

#include "GameplayTagsManager.h"
#include "GameplayTagContainer.h"


struct FXGNativeGameplayTags : public FGameplayTagNativeAdder
{

	FGameplayTag XG_Test_1;
	FGameplayTag XG_Test_2;
	FGameplayTag XG_Test_3;


	FORCEINLINE static const FXGNativeGameplayTags& Get() { return XGNativeGameplayTags; }

protected:
	virtual void AddTags() override
	{
		UGameplayTagsManager& Manager = UGameplayTagsManager::Get();

		XG_Test_1 = Manager.AddNativeGameplayTag(TEXT("XG.Test.1"));
		XG_Test_2 = Manager.AddNativeGameplayTag(TEXT("XG.Test.2"));
		XG_Test_3 = Manager.AddNativeGameplayTag(TEXT("XG.Test.3"));




	}


private:
	static FXGNativeGameplayTags XGNativeGameplayTags;
};

