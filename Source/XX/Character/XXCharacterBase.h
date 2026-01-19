// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Character/MMAlsCharacter.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XXCharacterBase.generated.h"

class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

/**
 * 
 */
UCLASS(Abstract)
class XX_API AXXCharacterBase : public AMMAlsCharacter, public IXXGASInterface
{
	GENERATED_BODY()
	
public:
	AXXCharacterBase(const FObjectInitializer& ObjectInitializer);

	// IXXGASInterface Start~
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() const override { return AbilitySystem; };
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() const override { return AttributeSet; };
	// IXXGASInterface End~

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere)
	UXXBaseAbilitySystemComponent* AbilitySystem;

	UPROPERTY(VisibleAnywhere)
	UXXBaseAttributeSet* AttributeSet;

	UPROPERTY(EditAnywhere, Category = "GAS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> InitAbilityClassArr;

	UPROPERTY(EditAnywhere, Category = "GAS|Effects")
	TArray<TSubclassOf<UGameplayEffect>> InitEffectClassArr;

};
