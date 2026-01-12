// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
#include "XXGASBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class XX_API UXXGASBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static bool ApplyEffectToTarget(
		FActiveGameplayEffectHandle& ActiveEffectHandle,
		UObject* Source,
		AActor* Target,
		TSubclassOf<UGameplayEffect> EffectClass,
		float Level = 1.f
	);

	UFUNCTION(BlueprintCallable)
	static bool RemoveEffectFromTarget(
		const FActiveGameplayEffectHandle& ActiveEffectHandle, 
		AActor* Target,
		int32 StacksToRemove = 1
	);
};
