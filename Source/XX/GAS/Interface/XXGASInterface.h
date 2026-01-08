// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "XXGASInterface.generated.h"

class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UXXGASInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class XX_API IXXGASInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() = 0;
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() = 0;
};
