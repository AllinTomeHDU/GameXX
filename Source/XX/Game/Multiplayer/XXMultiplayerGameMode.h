// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "XXMultiplayerGameMode.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAllPlayersLoadingComplete, bool bWasSuccessful);

class AXXMultiplayerGameState;

/**
 * 
 */
UCLASS()
class XX_API AXXMultiplayerGameMode : public AGameMode
{
	GENERATED_BODY()

	class UMultiplayerRoomSubsystem* RoomSubsystem;
	
public:
	FOnAllPlayersLoadingComplete OnAllPlayersLoadingCompleteDelegate;
	
public:
	virtual void BeginPlay() override;
	virtual void PostSeamlessTravel() override;
	virtual void HandleSeamlessTravelPlayer(AController*& C) override;

private:
	void StartMultiplayerGame();


private:
	UPROPERTY()
	AXXMultiplayerGameState* MultiGameState;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 MaxPlayerNum{ 1 };

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 LoadedPlayerNum{ 0 };
};
