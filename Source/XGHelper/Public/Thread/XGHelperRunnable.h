// Copyright 2023 Xiao Gang. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"

class FXGHelperRunnable :public FRunnable
{
public:
	FXGHelperRunnable(FString ThreadName) 
	:XGThreadName(ThreadName)
	{

	}

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Exit() override;
	virtual void Stop() override;

	FString XGThreadName;




	static FCriticalSection CriticalSection;
protected:
	bool bRunning = true;

};