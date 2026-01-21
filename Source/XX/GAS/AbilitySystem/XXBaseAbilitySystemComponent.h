// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "XXBaseAbilitySystemComponent.generated.h"

class UGameplayAbility;

/**
 * 
 */
UCLASS()
class XX_API UXXBaseAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilitiesClass);

protected:
	virtual void OnEffectApplied(
		UAbilitySystemComponent* ASC,
		const FGameplayEffectSpec& EffectSpec,
		FActiveGameplayEffectHandle ActiveEffectHandle
	);
	
private:

};
