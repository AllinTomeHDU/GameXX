// Copyright: Jichao Luo


#include "XXUserWidgetBase.h"
#include "XX/UI/Controller/XXWidgetControllerObject.h"
#include "XX/Controller/XXHeroPlayerController.h"
#include "XX/Player/XXHeroPlayerState.h"


void UXXUserWidgetBase::InitWidgetController()
{
	checkf(WidgetControllerClass, TEXT("WidgetControllerClass Is Null"));
	if (!IsValid(WidgetController))
	{
		WidgetController = NewObject<UXXWidgetControllerObject>(GetWorld(), WidgetControllerClass);
	}
	WidgetController->Init();
	OnInitWidgetControllerComplete();
}

void UXXUserWidgetBase::SetWidgetController(UXXWidgetControllerObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnSetWidgetControllerComplete();
}
