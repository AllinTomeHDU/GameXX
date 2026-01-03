// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Controller/MMAlsPlayerController.h"
#include "XXHeroPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class XX_API AXXHeroPlayerControllerBase : public AMMAlsPlayerController
{
	GENERATED_BODY()
	
public:
	AXXHeroPlayerControllerBase();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(Server, Reliable)
	void Server_SpawnHeroCharacter(UClass* InClass);
};
