// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "XXMultiplayerGameState.generated.h"

/**
 * 
 */
UCLASS()
class XX_API AXXMultiplayerGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	AXXMultiplayerGameState();
	
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_CloseTransitionWidget(const bool bForce);

protected:


};
