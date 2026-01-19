// Copyright: Jichao Luo


#include "XXBaseGameplayAbility.h"


void UXXBaseGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!HasAuthority(&ActivationInfo)) return;

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString(TEXT("Activate Ability C++")));
}
