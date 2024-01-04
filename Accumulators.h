// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpacecraftSubsystem.h"
#include "Accumulators.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API UAccumulators : public UActorComponent
{
	GENERATED_BODY()

public:

	UAccumulators();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentEnergyLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxEnergyLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetEnergyPercentage();

	void Charge(float Power, float Time);

	void Discharge(float Power, float Time);

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleInstanceOnly)
	float CurrentEnergyLevel;

	UPROPERTY(EditDefaultsOnly)
	float MaxEnergyLevel;
};
