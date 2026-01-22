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
		WidgetController = NewObject<UObject>(GetWorld(), WidgetControllerClass);
	}
	if (auto WC = Cast<UXXWidgetControllerObject>(WidgetController))
	{
		WC->Init();
	}
	OnInitWidgetControllerComplete();
}

void UXXUserWidgetBase::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnSetWidgetControllerComplete();
}
