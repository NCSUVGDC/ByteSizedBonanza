// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class VGDC_MinigamesEditorTarget : TargetRules
{
	public VGDC_MinigamesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "VGDC_Minigames" } );
	}
}
