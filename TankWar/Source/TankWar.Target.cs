// Copy Right Ashton

using UnrealBuildTool;
using System.Collections.Generic;

public class TankWarTarget : TargetRules
{
	public TankWarTarget(TargetInfo Target) : base (Target)
	{
		Type = TargetType.Game;
		
		ExtraModuleNames.Add("TankWar");
	}
}
