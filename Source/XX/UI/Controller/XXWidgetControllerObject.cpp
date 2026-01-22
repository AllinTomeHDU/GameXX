// Copyright: Jichao Luo


#include "XXWidgetControllerObject.h"
#include "XX/Controller/XXHeroPlayerController.h"
#include "XX/Player/XXHeroPlayerState.h"


void UXXWidgetControllerObject::Init()
{
	PlayerController = Cast<AXXHeroPlayerController>(GetWorld()->GetFirstPlayerController());
	check(PlayerController);
	PlayerState = Cast<AXXHeroPlayerState>(PlayerController->GetPlayerState<APlayerState>());
	check(PlayerState);
	AbilitySystem = PlayerState->GetBaseAbilitySystemComponent();
	AttributeSet = PlayerState->GetBaseAttributeSet();
	check(AbilitySystem && AttributeSet);

	BindCallbacksToDependencies();
}

