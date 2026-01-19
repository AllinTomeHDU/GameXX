// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct XX_API FXXGameplayTagsManager
{
public:
	static const FXXGameplayTagsManager& Get() { return GameplayTagsManager; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attribute_Test;

protected:


private:
	static FXXGameplayTagsManager GameplayTagsManager;
};
