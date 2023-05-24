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

			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			}
			);
	}
}
