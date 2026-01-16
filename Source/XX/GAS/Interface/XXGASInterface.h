// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AbilitySystemInterface.h"
#include "XXGASInterface.generated.h"

class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UXXGASInterface : public UAbilitySystemInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class XX_API IXXGASInterface : public IAbilitySystemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() const = 0;
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() const = 0;

	virtual int32 GetPlayerLevel() const { return 0; }
};
