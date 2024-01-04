// Fill out your copyright notice in the Description page of Project Settings.

#include "Shields.h"

UShields::UShields()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UShields::BeginPlay()
{
	Super::BeginPlay();
}

void UShields::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

int32 UShields::GetCurrentShieldsLevel()
{
	return CurrentShieldsLevel;
}

int32 UShields::GetMaxShieldsLevel()
{
	return MaxShieldsLevel;
}

float UShields::GetShieldsPercentage()
{
	return CurrentShieldsLevel / MaxShieldsLevel;
}

int32 UShields::GetShieldsRestorationRate()
{
	return ShieldsRestorationRate;
}
