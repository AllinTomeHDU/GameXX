// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XXHeroPlayerState.generated.h"

class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

/**
 * 
 */
UCLASS()
class XX_API AXXHeroPlayerState : public APlayerState, public IXXGASInterface
{
	GENERATED_BODY()
	
public:
	AXXHeroPlayerState();
	
	// IXXGASInterface Start~
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() override { return AbilitySystem; };
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() override { return AttributeSet; };
	// IXXGASInterface End~

protected:
	UPROPERTY(VisibleAnywhere)
	UXXBaseAbilitySystemComponent* AbilitySystem;

	UPROPERTY(VisibleAnywhere)
	UXXBaseAttributeSet* AttributeSet;
};
