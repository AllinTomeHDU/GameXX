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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	
	UFUNCTION(Server, Reliable)
	void Server_SpawnHeroCharacter(UClass* InClass);

private:
	UPROPERTY(EditAnywhere, Category = "GAS|Inputs")
	UInputMappingContext* IMC_GAS;

	UPROPERTY(EditAnywhere, Category = "GAS|Inputs")
	int32 GASInputsPriority = 1;

	UPROPERTY(EditAnywhere, Category = "GAS|Inputs")
	UInputAction* IA_AbilityQ;
};
