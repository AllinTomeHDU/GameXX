// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "Abilities/GameplayAbility.h"
#include "XXPDA_AbilitiesBase.generated.h"

class UInputMappingContext;
class UGameplayAbility;


USTRUCT(BlueprintType, Blueprintable)
struct FAbilityInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* IA_Ability;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ETriggerEvent TriggerMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> AbilityClass;

	bool IsValid() const
	{
		return IA_Ability && TriggerMode != ETriggerEvent::None && AbilityClass;
	}
};

/**
 * 
 */
UCLASS()
class XX_API UXXPDA_AbilitiesBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent(ACharacter* Chr);

private:
	UPROPERTY(EditAnywhere)
	UInputMappingContext* IMC_Abilities;

	UPROPERTY(EditAnywhere)
	int32 InputPriority = 1;
	
	UPROPERTY(EditAnywhere)
	TArray<FAbilityInfo> AbilitiesInfo;
};
