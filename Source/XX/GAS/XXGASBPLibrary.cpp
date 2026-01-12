// Copyright: Jichao Luo


#include "XXGASBPLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"


bool UXXGASBPLibrary::ApplyEffectToTarget(
	FActiveGameplayEffectHandle& ActiveEffectHandle, 
	UObject* Source, 
	AActor* Target, 
	TSubclassOf<UGameplayEffect> EffectClass, 
	float Level)
{
	if (!IsValid(Source) || !IsValid(Target) || !IsValid(EffectClass)) return false;

	auto TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (!IsValid(TargetASC)) return false;

	FGameplayEffectContextHandle ContextHandle = TargetASC->MakeEffectContext();
	ContextHandle.AddSourceObject(Source);
	const FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(EffectClass, Level, ContextHandle);
	ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	return ActiveEffectHandle.IsValid();
}

bool UXXGASBPLibrary::RemoveEffectFromTarget(
	const FActiveGameplayEffectHandle& ActiveEffectHandle, 
	AActor* Target,
	int32 StacksToRemove)
{
	if (!ActiveEffectHandle.IsValid() || !IsValid(Target)) return false;

	auto TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (!IsValid(TargetASC)) return false;

	return TargetASC->RemoveActiveGameplayEffect(ActiveEffectHandle, StacksToRemove);
}
