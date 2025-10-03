using UnrealBuildTool;

public class %MODULE_NAME%Game : ModuleRules
{
    public %MODULE_NAME%Game(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "%MODULE_NAME%Game"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EnhancedInput",
				"DeveloperSettings",
				"GameplayTags",
                "CommonUI",

                // Our modules belong here:
                "OurGame"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );
    }
}
