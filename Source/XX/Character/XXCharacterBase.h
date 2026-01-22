// Copyright: Jichao Luo

#pragma once

#include "CoreMinimal.h"
#include "MotionMatchingAls/3C/Character/MMAlsCharacter.h"
#include "XX/GAS/Interface/XXGASInterface.h"
#include "XXCharacterBase.generated.h"

class UWidgetComponent;
class UXXBaseAbilitySystemComponent;
class UXXBaseAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

/**
 * 
 */
UCLASS(Abstract)
class XX_API AXXCharacterBase : public AMMAlsCharacter, public IXXGASInterface
{
	GENERATED_BODY()
	
public:
	AXXCharacterBase(const FObjectInitializer& ObjectInitializer);

	// IXXGASInterface Start~
	virtual UXXBaseAbilitySystemComponent* GetBaseAbilitySystemComponent() const override { return AbilitySystem; };
	virtual UXXBaseAttributeSet* GetBaseAttributeSet() const override { return AttributeSet; };
	virtual int32 GetCharacterLevel() const { return CharacterLevel; }
	// IXXGASInterface End~

	UFUNCTION(BlueprintCallable)
	void LevelUp(int32 Number = 1);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void Server_LevelUp(int32 Number);

	UFUNCTION()
	void OnRep_CharacterLevel(int32 PrevLevel);

	virtual void OnLevelUp(int32 PrevLevel);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HeadWidget", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* HeadTopWidget;

	UPROPERTY(VisibleAnywhere)
	UXXBaseAbilitySystemComponent* AbilitySystem;

	UPROPERTY(VisibleAnywhere)
	UXXBaseAttributeSet* AttributeSet;

	UPROPERTY(EditAnywhere, Category = "GAS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> InitAbilityClassArr;

	UPROPERTY(EditAnywhere, Category = "GAS|Effects")
	TArray<TSubclassOf<UGameplayEffect>> InitEffectClassArr;

	UPROPERTY(EditAnywhere, Category = "GAS|Effects")
	TSubclassOf<UGameplayEffect> GrowthAttributesEffectClass;

	UPROPERTY(EditAnywhere, Category = "GAS|Effects")
	TSubclassOf<UGameplayEffect> ResetStatusEffectClass;

	UPROPERTY(ReplicatedUsing = "OnRep_CharacterLevel", EditAnywhere, BlueprintReadWrite, Category = "GAS", meta = (AllowPirvateAccess = "true"))
	int32 CharacterLevel = 1;

};
