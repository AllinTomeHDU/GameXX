// Copyright: Jichao Luo


#include "XXUserWidgetBase.h"


void UXXUserWidgetBase::SetWidgetController(UXXWidgetControllerObject* InWidgetController)
{
	WidgetController = InWidgetController;
	SetWidgetControllerBP();
}
