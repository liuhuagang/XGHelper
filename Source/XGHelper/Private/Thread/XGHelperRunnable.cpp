// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperRunnable.h"




FCriticalSection FXGHelperRunnable::CriticalSection;
bool FXGHelperRunnable::Init()
{	//������HelperRunnable�߳� ���ܴ�ӡ��־
	return true;
}

uint32 FXGHelperRunnable::Run()
{
	//������HelperRunnable�߳� ���ܴ�ӡ��־
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
	//������HelperRunnable�߳� ���ܴ�ӡ��־
}

void FXGHelperRunnable::Stop()
{
	//���ﲻ��HelperRunnable�߳�,���������߳�Ҳ�����������߳�
	UE_LOG(LogTemp, Display, TEXT("[%s]FXGHelperRunnable[%s] begin to stop"), *FString(__FUNCTION__), *XGThreadName);
	FScopeLock Lock(&CriticalSection);
	bRunning = false;

}
