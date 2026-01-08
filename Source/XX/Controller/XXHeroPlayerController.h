// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Controller/MMAlsPlayerController.h"
#include "XXHeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class XX_API AXXHeroPlayerController : public AMMAlsPlayerController
{
	GENERATED_BODY()
	
public:
	AXXHeroPlayerController();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(Server, Reliable)
	void Server_SpawnHeroCharacter(UClass* InClass);
};
