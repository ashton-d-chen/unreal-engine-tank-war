// Copy Right Ashton

using UnrealBuildTool;
using System.Collections.Generic;

public class TankWarEditorTarget : TargetRules
{
	public TankWarEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		
		ExtraModuleNames.Add("TankWar");
	}
}
