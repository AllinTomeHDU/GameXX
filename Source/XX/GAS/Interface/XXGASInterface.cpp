// Copyright: Jichao Luo


#include "XXGASInterface.h"
#include "XX/GAS/AbilitySystem/XXBaseAbilitySystemComponent.h"


// Add default functionality here for any IXXGASInterface functions that are not pure virtual.

UAbilitySystemComponent* IXXGASInterface::GetAbilitySystemComponent() const
{
    return Cast<UAbilitySystemComponent>(GetBaseAbilitySystemComponent());
}
