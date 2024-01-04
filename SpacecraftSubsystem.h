// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "SpacecraftSubsystem.generated.h"

enum ESubsystemState : uint8;
class ASpacecraft;

UCLASS()
class SPACEGAME_API ASpacecraftSubsystem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	
	ASpacecraftSubsystem();
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetCurrentDurabilityPoints();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetMaxDurabilityPoints();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetDurabilityCriticalLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetDurabilityPercentage();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsBroken();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsPowered();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsFunctional();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ESubsystemState GetSubsystemState();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPowerUsage();

	ASpacecraft* GetParentSpacecraft();

	void PowerOn();

	void PowerOff();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly)
	int32 CurrentDurabilityPoints;
	
	UPROPERTY(EditDefaultsOnly)
	int32 MaxDurabilityPoints;

	// on critical level subsystem no longer works
	UPROPERTY(EditDefaultsOnly)
	int32 DurabilityCriticalLevel;

	UPROPERTY(EditDefaultsOnly)
	float PowerUsage;

	ASpacecraft* ParentSpacecraft;

	void FindParentSpacecraft();

	bool bIsPowered = false;
};
