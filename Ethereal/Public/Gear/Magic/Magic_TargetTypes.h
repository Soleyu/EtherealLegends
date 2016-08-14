// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once
#include "Magic_TargetTypes.generated.h"
/**
*
*/

UENUM(BlueprintType)
enum class EMagic_TargetTypes : uint8
{
	TT_Player UMETA(DisplayName = "Player"),
	TT_Enemy UMETA(DisplayName = "Enemy"),
};
