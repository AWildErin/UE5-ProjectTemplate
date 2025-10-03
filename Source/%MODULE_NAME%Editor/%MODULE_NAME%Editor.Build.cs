using UnrealBuildTool;

public class %MODULE_NAME%Editor : ModuleRules
{
    public %MODULE_NAME%Editor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "%MODULE_NAME%Editor"
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
                "EditorFramework",
                "UnrealEd",
                "PhysicsCore",

                // Our modules belong here:
                "OurEditor",
                "%MODULE_NAME%Game",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "InputCore",
                "Slate",
                "SlateCore",
                "ToolMenus",
                "EditorStyle",
                "DataValidation",
                "MessageLog",
                "Projects",
                "DeveloperToolSettings",
                "CollectionManager",
                "SourceControl",
                "Chaos"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );
    }
}
