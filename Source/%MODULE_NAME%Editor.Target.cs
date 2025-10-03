using UnrealBuildTool;
using System.Collections.Generic;

public class %MODULE_NAME%EditorTarget : TargetRules
{
    public %MODULE_NAME%EditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.AddRange(new string[] { "%MODULE_NAME%Game", "%MODULE_NAME%Editor" });
    }
}
