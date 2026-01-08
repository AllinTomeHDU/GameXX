// Copyright: Jichao Luo


#include "XXMultiplayerGameMode.h"
#include "XXMultiplayerGameState.h"
#include "Room/MultiplayerRoomSubsystem.h"
#include "GameFramework/GameState.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "Interfaces/OnlineSessionInterface.h"


void AXXMultiplayerGameMode::BeginPlay()
{
	Super::BeginPlay();

}

void AXXMultiplayerGameMode::PostSeamlessTravel()
{
	Super::PostSeamlessTravel();

}

void AXXMultiplayerGameMode::HandleSeamlessTravelPlayer(AController*& C)
{
	Super::HandleSeamlessTravelPlayer(C);

	if (!IsValid(RoomSubsystem))
	{
		RoomSubsystem = GetGameInstance()->GetSubsystem<UMultiplayerRoomSubsystem>();
		if (!IsValid(RoomSubsystem)) return;
	}
	auto SessionsInterface = IOnlineSubsystem::Get()->GetSessionInterface();
	if (!IsValid(RoomSubsystem) || !SessionsInterface.IsValid()) return;

	if (C->IsLocalController())
	{
		// 先于BeginPlay()的初始化
		RoomSubsystem->OnTransionWidgetCloseDelegate.AddUObject(this, &ThisClass::StartMultiplayerGame);
		if (auto CurrentSession = SessionsInterface->GetNamedSession(NAME_GameSession))
		{
			CurrentSession->SessionSettings.Get(FName("MaxPlayerNum"), MaxPlayerNum);
		}
	}

	MultiGameState = Cast<AXXMultiplayerGameState>(GameState);
	if (IsValid(MultiGameState))
	{
		if (++LoadedPlayerNum == MaxPlayerNum)
		{
			MultiGameState->Multicast_CloseTransitionWidget(false);
			OnAllPlayersLoadingCompleteDelegate.Broadcast(true);
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
		FString::Printf(TEXT("Player %s joined after travel, %d/%d"),
			*C->GetName(), LoadedPlayerNum, MaxPlayerNum));
}

void AXXMultiplayerGameMode::StartMultiplayerGame()
{
	if (IsValid(MultiGameState))
	{
		MultiGameState->Multicast_CloseTransitionWidget(true);
	}
	bool bAllPlayersLoaded = (LoadedPlayerNum == MaxPlayerNum);
	OnAllPlayersLoadingCompleteDelegate.Broadcast(bAllPlayersLoaded);
}
