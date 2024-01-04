// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spacecraft.generated.h"

class UEngines;
class UShields;
class UGravityGenerator;
class UOxygenGenerator;
class UPowerGenerator;
class UAccumulators;
class ASpacecraftSubsystem;

UCLASS()
class SPACEGAME_API ASpacecraft : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASpacecraft();

	virtual void Tick(float DeltaTime) override;

	UPowerGenerator* GetPowerGenerator();
	
	UAccumulators* GetAccumulators();

	UOxygenGenerator* GetOxygenGenerator();

	UGravityGenerator* GetGravityGenerator();

	UShields* GetShields();

	UEngines* GetEngines();

	ASpacecraftSubsystem* GetPowerGeneratorSubsystem();

	ASpacecraftSubsystem* GetAccumulatorsSubsystem();

	ASpacecraftSubsystem* GetOxygenGeneratorSubsystem();

	ASpacecraftSubsystem* GetGravityGeneratorSubsystem();

	ASpacecraftSubsystem* GetShieldsSubsystem();

	ASpacecraftSubsystem* GetEnginesSubsystem();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentEnergyLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxEnergyLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetEnergyPercentage();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPowerGain();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPowerUsage();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPowerBalance();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetCurrentOxygenLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetMaxOxygenLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasGravityEnabled();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetShieldsLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasEnginesRunning();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasAllSubsystemsFunctional();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasSomeSubsystemsFunctional();

	TArray<ASpacecraftSubsystem*> GetSubsystems();
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleInstanceOnly)
	int32 CurrentOxygenLevel;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxOxygenLevel;

	TArray<ASpacecraftSubsystem*> Subsystems;

	UPowerGenerator* PowerGenerator;

	UAccumulators* Accumulators;

	UOxygenGenerator* OxygenGenerator;

	UGravityGenerator* GravityGenerator;

	UShields* Shields;

	UEngines* Engines;

	ASpacecraftSubsystem* PowerGeneratorSubsystem;

	ASpacecraftSubsystem* AccumulatorsSubsystem;

	ASpacecraftSubsystem* OxygenGeneratorSubsystem;

	ASpacecraftSubsystem* GravityGeneratorSubsystem;

	ASpacecraftSubsystem* ShieldsSubsystem;

	ASpacecraftSubsystem* EnginesSubsystem;

	void AddSubsystem(ASpacecraftSubsystem* Subsystem);

	void FindSubsystems();

	void UpdatePower(float DeltaTime);

	void PowerOnSubsystems();

	void PowerOffSubsystems();
};
