// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "XXBaseAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXBaseAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:
	virtual void OnEffectApplied(
		UAbilitySystemComponent* ASC,
		const FGameplayEffectSpec& EffectSpec,
		FActiveGameplayEffectHandle ActiveEffectHandle
	);
	
};
