// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperRunnable.h"




FCriticalSection FXGHelperRunnable::CriticalSection;
bool FXGHelperRunnable::Init()
{
	return true;
}

uint32 FXGHelperRunnable::Run()
{
	while (true)
	{

		FScopeLock Lock(&CriticalSection);
		if (!bRunning)
		{
			break;
		}
		Lock.Unlock();
		FPlatformProcess::Sleep(0.04);




	}




	return 0;
}

void FXGHelperRunnable::Exit()
{

}

void FXGHelperRunnable::Stop()
{
	UE_LOG(LogTemp, Display, TEXT("FConsumeSoundRunnable[%s] begin to stop"), *MyThreadName);
	FScopeLock Lock(&CriticalSection);
	bRunning = false;

}
