// Copyright: Jichao Luo


#include "XXWidgetControllerObject.h"


void UXXWidgetControllerObject::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystem = Params.AbilitySystem;
	AttributeSet = Params.AttributeSet;
}
