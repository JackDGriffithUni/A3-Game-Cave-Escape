// Pls no steal, I worked hard on it

using UnrealBuildTool;
using System.Collections.Generic;

public class CaveEscapeA3GameEditorTarget : TargetRules
{
	public CaveEscapeA3GameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "CaveEscapeA3Game" } );
	}
}
