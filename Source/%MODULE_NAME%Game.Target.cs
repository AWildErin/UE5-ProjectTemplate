using UnrealBuildTool;
using System.Collections.Generic;

public class %MODULE_NAME%GameTarget : TargetRules
{
    public %MODULE_NAME%GameTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("%MODULE_NAME%Game");
    }
}
