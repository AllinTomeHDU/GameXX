// Copyright: Jichao Luo


#include "XXGameplayTagsManager.h"
#include "GameplayTagsManager.h"


FXXGameplayTagsManager FXXGameplayTagsManager::GameplayTagsManager;

void FXXGameplayTagsManager::InitializeNativeGameplayTags()
{
	GameplayTagsManager.Attribute_Test = UGameplayTagsManager::Get().
		AddNativeGameplayTag(FName("Attributes.Test"), FString(TEXT("Test Tag")));

}
