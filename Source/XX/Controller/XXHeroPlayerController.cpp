// Copyright: Jichao Luo


#include "XXHeroPlayerController.h"
#include "Room/MultiplayerRoomSubsystem.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"


AXXHeroPlayerController::AXXHeroPlayerController()
{
	bReplicates = true;
}

void AXXHeroPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	bShowMouseCursor = false;

	if (IsLocalPlayerController())
	{
		if (auto RoomSubsystem = GetGameInstance()->GetSubsystem<UMultiplayerRoomSubsystem>())
		{
			if (UClass* InClass = RoomSubsystem->GetSavedCharacterClass())
			{
				Server_SpawnHeroCharacter(InClass);
			}
		}
	}
}

void AXXHeroPlayerController::Server_SpawnHeroCharacter_Implementation(UClass* InClass)
{
	UWorld* World = GetWorld();

	// 为避免角色生成时位置冲突，可依据玩家数摆放出生点
	AActor* StartPoint = nullptr;
	TArray<AActor*> FoundStarts;
	UGameplayStatics::GetAllActorsOfClass(World, APlayerStart::StaticClass(), FoundStarts);
	checkf(FoundStarts.Num() > 0, TEXT("Can't found player start point..."));
	for (auto& Tmp : FoundStarts)
	{
		if (!Tmp->ActorHasTag(TEXT("Used")))
		{
			StartPoint = Tmp;
			Tmp->Tags.Add(TEXT("Used"));
			break;
		}
	}
	if (!StartPoint)
	{
		StartPoint = FoundStarts[0];
	}
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetPawn();
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector Loc = StartPoint->GetActorLocation();
	FRotator Rot = StartPoint->GetActorRotation();
	ACharacter* SpawnedCharacter = World->SpawnActor<ACharacter>(InClass, Loc, Rot, SpawnParams);

	Possess(SpawnedCharacter);
}
