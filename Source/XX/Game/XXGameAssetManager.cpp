// Copyright: Jichao Luo


#include "XXGameAssetManager.h"
#include "XXGameplayTagsManager.h"


UXXGameAssetManager& UXXGameAssetManager::Get()
{
	UXXGameAssetManager* GameAssetManager = Cast<UXXGameAssetManager>(GEngine->AssetManager);
	return *GameAssetManager;
}

void UXXGameAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FXXGameplayTagsManager::InitializeNativeGameplayTags();
}
