// Copyright: Jichao Luo


#include "XXMultiplayerGameState.h"
#include "Room/MultiplayerRoomSubsystem.h"


AXXMultiplayerGameState::AXXMultiplayerGameState()
{
	bReplicates = true;
}

void AXXMultiplayerGameState::Multicast_CloseTransitionWidget_Implementation(const bool bForce)
{
    if (auto RoomSubsystem = GetGameInstance()->GetSubsystem<UMultiplayerRoomSubsystem>())
    {
        if (RoomSubsystem->IsTransiotionPlaying())
        {
            RoomSubsystem->RequestCloseTransitionWidget(bForce);
        }
    }
}
