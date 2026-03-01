// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CrashCourse : ModuleRules
{
	public CrashCourse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTasks",
			"GameplayTags",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
	}
}
