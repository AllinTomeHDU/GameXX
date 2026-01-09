// Copyright: Jichao Luo


#include "XXGameHUD.h"
#include "XX/UI/Widget/XXUserWidgetBase.h"
#include "XX/UI/Controller/Overlay/XXOverlayWidgetController.h"


void AXXGameHUD::BeginPlay()
{
	Super::BeginPlay();

}

void AXXGameHUD::InitOverlay()
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass Is Null"));
	if (!IsValid(OverlayWidget))
	{
		OverlayWidget = CreateWidget<UXXUserWidgetBase>(GetWorld(), OverlayWidgetClass);
		OverlayWidget->AddToViewport();
	}
	OverlayWidget->InitWidgetController();
}