// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperPlatform.h"
#include "IDesktopPlatform.h"
#include "DesktopPlatformModule.h"


#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"


void UXGHelperPlatformBPLibrary::XGHelperOpenFileDialog()
{
	////�洢��ѡ���ļ�·��
	TArray<FString> FilePath;

	//�����ļ�����
	//FString FileType = TEXT("XmlFile (*.xml)|*.xml"); 
	// 
	//���ַ���Ϊ�������ļ�
	FString FileType = TEXT("");

	//�ļ�ѡ�񴰿�Ĭ�Ͽ���·��
	FString DefaultPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());

	//��һ�����������˸����ڵľ��,����Ի���رյ�ʱ�򵯳�����������
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	bool bSuccess = DesktopPlatform->OpenFileDialog
	(FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
		TEXT("XGHelperDialog"),
		DefaultPath, TEXT(""),
		*FileType,
		EFileDialogFlags::None,
		FilePath);

	if (bSuccess)
	{
		//Do something...
	}
	else
	{

	}

}

void UXGHelperPlatformBPLibrary::XGHelperFileOperate()
{
	//���õ�ƽ̨�ļ����������ٻ�ȡ�ļ������ӿڣ��ٵ�������Ľӿڽ��в���
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();



}
