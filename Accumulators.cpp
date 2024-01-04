// Fill out your copyright notice in the Description page of Project Settings.

#include "Accumulators.h"

UAccumulators::UAccumulators()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAccumulators::BeginPlay()
{
	Super::BeginPlay();
}

void UAccumulators::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UAccumulators::GetCurrentEnergyLevel()
{
	return CurrentEnergyLevel;
}

float UAccumulators::GetMaxEnergyLevel()
{
	return MaxEnergyLevel;
}

float UAccumulators::GetEnergyPercentage()
{
	return CurrentEnergyLevel / MaxEnergyLevel;
}

void UAccumulators::Charge(float Power, float Time)
{
	float PowerIncrease = Power * Time / 3600;
	CurrentEnergyLevel = FMath::Clamp(CurrentEnergyLevel + PowerIncrease, CurrentEnergyLevel, MaxEnergyLevel);
}

void UAccumulators::Discharge(float Power, float Time)
{
	float PowerDecrease = Power * Time / 3600;
	CurrentEnergyLevel = FMath::Clamp(CurrentEnergyLevel - PowerDecrease, 0.f, CurrentEnergyLevel);
}
