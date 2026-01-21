// Copyright: Jichao Luo


#include "XXPDA_AbilitiesBase.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XX/GAS/AbilitySystem/XXBaseAbilitySystemComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void UXXPDA_AbilitiesBase::SetupInputComponent(ACharacter* Chr)
{
	if (!IsValid(Chr)) return;
	checkf(IMC_Abilities, TEXT("IMC_Abilities is nullptr"));

	if (auto EnhancedInputComp = Cast<UEnhancedInputComponent>(Chr->InputComponent))
	{
		for (const auto& Info : AbilitiesInfo)
		{
			checkf(Info.IsValid(), TEXT("AbilityInfo is not Valid"));
			EnhancedInputComp->BindActionValueLambda(
				Info.IA_Ability,
				Info.TriggerMode,
				[Chr, Info](const FInputActionValue& InputValue)
				{
					if (IXXGASInterface* GASInterface = Cast<IXXGASInterface>(Chr))
					{
						if (auto ASC = GASInterface->GetBaseAbilitySystemComponent())
						{
							ASC->TryActivateAbilityByClass(Info.AbilityClass);
						}
					}
				}
			);
		}
	}

	if (auto PC = Cast<APlayerController>(Chr->GetController()))
	{
		auto EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());
		if (EnhancedInputSubsystem)
		{
			EnhancedInputSubsystem->AddMappingContext(IMC_Abilities, InputPriority);
		}
	}
}
