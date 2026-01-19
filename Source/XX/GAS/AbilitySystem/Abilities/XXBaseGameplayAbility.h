// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "XXBaseGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:


protected:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData
	);
	
	
};
