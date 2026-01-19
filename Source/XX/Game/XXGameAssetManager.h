// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "XXGameAssetManager.generated.h"

/**
 * 将GameplayTags设置为变量，避免查询时硬编码
 */
UCLASS()
class XX_API UXXGameAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static UXXGameAssetManager& Get();
	
	virtual void StartInitialLoading() override;
	
};
