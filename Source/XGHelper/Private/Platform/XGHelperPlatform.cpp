// Copyright 2023 Xiao Gang. All Rights Reserved.
#include "XGHelperPlatform.h"
#include "IDesktopPlatform.h"
#include "DesktopPlatformModule.h"


#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"


void UXGHelperPlatformBPLibrary::XGHelperOpenFileDialog()
{
	////存储被选中文件路径
	TArray<FString> FilePath;

	//过滤文件类型
	//FString FileType = TEXT("XmlFile (*.xml)|*.xml"); 
	// 
	//空字符串为不过滤文件
	FString FileType = TEXT("");

	//文件选择窗口默认开启路径
	FString DefaultPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());

	//第一个参数传入了父窗口的句柄,避免对话框关闭的时候弹出到其他窗口
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
	//先拿到平台文件管理器，再获取文件操作接口，再调用里面的接口进行操作
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();



}
