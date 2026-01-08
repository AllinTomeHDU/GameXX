// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Character/MMAlsCharacter.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XXCharacterBase.generated.h"

class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

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
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() override { return AbilitySystem; };
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() override { return AttributeSet; };
	// IXXGASInterface End~

protected:
	


protected:
	UPROPERTY(VisibleAnywhere)
	UXXBaseAbilitySystemComponent* AbilitySystem;

	UPROPERTY(VisibleAnywhere)
	UXXBaseAttributeSet* AttributeSet;
	
};
