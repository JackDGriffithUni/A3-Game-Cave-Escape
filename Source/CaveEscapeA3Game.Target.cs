// Pls no steal, I worked hard on it

using UnrealBuildTool;
using System.Collections.Generic;

public class CaveEscapeA3GameTarget : TargetRules
{
	public CaveEscapeA3GameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "CaveEscapeA3Game" } );
	}
}
