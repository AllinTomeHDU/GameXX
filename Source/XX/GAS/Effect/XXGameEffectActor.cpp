// Copyright: Jichao Luo


#include "XXGameEffectActor.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XX/GAS/AbilitySystem/XXBaseAbilitySystemComponent.h"
#include "XX/GAS/AttributeSet/XXBaseAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"


AXXGameEffectActor::AXXGameEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AXXGameEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> InEffectClass)
{
	auto TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (!IsValid(TargetASC)) return;

	checkf(InEffectClass, TEXT("Applied GameplayEffectClass is Null"));
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(InEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());	// Hard code Level!!!
}
