// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperRunnable.h"




FCriticalSection FXGHelperRunnable::CriticalSection;
bool FXGHelperRunnable::Init()
{	//这里是HelperRunnable线程 不能打印日志
	return true;
}

uint32 FXGHelperRunnable::Run()
{
	//这里是HelperRunnable线程 不能打印日志
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
	//这里是HelperRunnable线程 不能打印日志
}

void FXGHelperRunnable::Stop()
{
	//这里不是HelperRunnable线程,可以是主线程也可以是其他线程
	UE_LOG(LogTemp, Display, TEXT("[%s]FXGHelperRunnable[%s] begin to stop"), *FString(__FUNCTION__), *XGThreadName);
	FScopeLock Lock(&CriticalSection);
	bRunning = false;

}
