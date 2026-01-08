// Copyright: Jichao Luo


#include "XXGameHUD.h"
#include "XX/UI/Widget/XXUserWidgetBase.h"
#include "XX/UI/Controller/XXOverlayWidgetController.h"


void AXXGameHUD::BeginPlay()
{
	Super::BeginPlay();

	
}

void AXXGameHUD::InitOverlay(AXXHeroPlayerController* PC, AXXHeroPlayerState* PS, UXXBaseAbilitySystemComponent* ASC, UXXBaseAttributeSet* AS)
{
	if (!IsValid(OverlayWidgetController))
	{
		OverlayWidgetController = NewObject<UXXWidgetControllerObject>(this, UXXOverlayWidgetController::StaticClass());
	}
	FWidgetControllerParams Params(PC, PS, ASC, AS);
	OverlayWidgetController->SetWidgetControllerParams(Params);

	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass Is Null"));
	if (!IsValid(OverlayWidget))
	{
		OverlayWidget = CreateWidget<UXXUserWidgetBase>(GetWorld(), OverlayWidgetClass);
		OverlayWidget->AddToViewport();
	}
	OverlayWidget->SetWidgetController(OverlayWidgetController);
}