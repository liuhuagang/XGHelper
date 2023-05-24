// Copyright 2023 Xiao Gang. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FXGHelperModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
