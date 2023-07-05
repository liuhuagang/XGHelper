// Copyright 2023 Xiao Gang. All Rights Reserved.

using UnrealBuildTool;

public class XGHelper : ModuleRules
{
	public XGHelper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
	
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                "XGHelper/Public/Core",
                "XGHelper/Public/Subsystem",
                "XGHelper/Public/Log",
                "XGHelper/Public/Thread",
                "XGHelper/Public/UMG",
                "XGHelper/Public/Enum",
                "XGHelper/Public/Object",
                "XGHelper/Public/Struct",
                "XGHelper/Public/TMap",
                "XGHelper/Public/TArray",
                "XGHelper/Public/Delegate",
				"XGHelper/Public/Platform",
                "XGHelper/Public/StreamableManager",
                "XGHelper/Public/CameraPixel"


            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
	
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UMG",
				"Slate",
				"SlateCore",
				"DesktopPlatform",

            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			}
			);
	}
}
