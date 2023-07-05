// Copyright 2023 Xiao Gang. All Rights Reserved.


#include "XGMediaPixelProcess.h"
#include "Engine/TextureRenderTarget2D.h"
#include "LogXGHelper.h"

AXGMediaPixelProcess::AXGMediaPixelProcess()
{

	PrimaryActorTick.bCanEverTick = false;

}

bool AXGMediaPixelProcess::ProcessData(UTextureRenderTarget2D* TextureRenderTarget2D)
{
	UE_LOG(LogXGHelper,Display,TEXT("%s"),*FString(__FUNCTION__));

	//将TextureRenderTarget2D中的像素数据读取出来
	if (TextureRenderTarget2D == nullptr) {
	
		return false;
	}
	FTextureRenderTargetResource* TextureRenderTargetResource = TextureRenderTarget2D->GameThread_GetRenderTargetResource();
	FReadSurfaceDataFlags ReadSurfaceDataFlags(RCM_UNorm);
	ReadSurfaceDataFlags.SetLinearToGamma(true);

	TArray<FColor> OutColors;
	OutColors.AddUninitialized(TextureRenderTarget2D->GetSurfaceWidth() * TextureRenderTarget2D->GetSurfaceHeight());
	TextureRenderTargetResource->ReadPixels(OutColors, ReadSurfaceDataFlags);

	//修改透明度
	for (FColor& Color : OutColors)
	{ 
		Color.A = 255;
	}
	
	//将数据转换为C风格类型的指针
	unsigned long DataSize = sizeof(unsigned char) * 4 * (TextureRenderTarget2D->GetSurfaceWidth() * TextureRenderTarget2D->GetSurfaceHeight());
	unsigned char* PixelData =(unsigned char*)FMemory::Malloc(DataSize);;


	FMemory::Memset(PixelData, 0, DataSize);

	int CusPos = 0;
	for (FColor& Color : OutColors) {
		FMemory::Memcpy(PixelData + CusPos, (unsigned char*)&Color.R, 1);
		CusPos += 1;
		FMemory::Memcpy(PixelData + CusPos, (unsigned char*)&Color.G, 1);
		CusPos += 1;
		FMemory::Memcpy(PixelData + CusPos, (unsigned char*)&Color.B, 1);
		CusPos += 1;
		FMemory::Memcpy(PixelData + CusPos, (unsigned char*)&Color.A, 1);
		CusPos += 1;
	}

	FMemory::Free(PixelData);


	return true;
}


void AXGMediaPixelProcess::BeginPlay()
{
	Super::BeginPlay();

}


void AXGMediaPixelProcess::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

