// Fill out your copyright notice in the Description page of Project Settings.

#include "SpacecraftSubsystem.h"

#include "SubsystemState.h"
#include "Spacecraft.h"

ASpacecraftSubsystem::ASpacecraftSubsystem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpacecraftSubsystem::BeginPlay()
{
	Super::BeginPlay();

	FindParentSpacecraft();
	CurrentDurabilityPoints = MaxDurabilityPoints;
}

void ASpacecraftSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 ASpacecraftSubsystem::GetCurrentDurabilityPoints()
{
	return CurrentDurabilityPoints;
}

int32 ASpacecraftSubsystem::GetMaxDurabilityPoints()
{
	return MaxDurabilityPoints;
}

int32 ASpacecraftSubsystem::GetDurabilityCriticalLevel()
{
	return DurabilityCriticalLevel;
}

float ASpacecraftSubsystem::GetDurabilityPercentage()
{
	return CurrentDurabilityPoints / MaxDurabilityPoints;
}

bool ASpacecraftSubsystem::IsBroken()
{
	return GetCurrentDurabilityPoints() <= GetDurabilityCriticalLevel();
}

bool ASpacecraftSubsystem::IsPowered()
{
	return bIsPowered;
}

bool ASpacecraftSubsystem::IsFunctional()
{
	return !IsBroken() && IsPowered();
}

ESubsystemState ASpacecraftSubsystem::GetSubsystemState()
{
	if(IsFunctional()) return ESubsystemState::Functional;
	else if(IsBroken()) return ESubsystemState::Broken;
	else return ESubsystemState::Unpowered;
}

float ASpacecraftSubsystem::GetPowerUsage()
{
	return PowerUsage;
}

ASpacecraft* ASpacecraftSubsystem::GetParentSpacecraft()
{
	return ParentSpacecraft;
}

void ASpacecraftSubsystem::FindParentSpacecraft()
{
	if(ASpacecraft* Parent = Cast<ASpacecraft>(GetParentActor()))
	{
		ParentSpacecraft = Parent;
		UE_LOG(LogTemp, Warning, TEXT("Successfully found parent spacecraft for subsystem %s"), *GetActorNameOrLabel());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find parent spacecraft for subsystem %s"), *GetActorNameOrLabel());
	}
}

void ASpacecraftSubsystem::PowerOn()
{
	bIsPowered = true;
}

void ASpacecraftSubsystem::PowerOff()
{
	bIsPowered = false;
}
