// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class VGDC_MinigamesTarget : TargetRules
{
	public VGDC_MinigamesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "VGDC_Minigames" } );
	}
}
