// Fill out your copyright notice in the Description page of Project Settings.

#include "Spacecraft.h"
#include "Accumulators.h"
#include "Engines.h"
#include "GravityGenerator.h"
#include "OxygenGenerator.h"
#include "PowerGenerator.h"
#include "Shields.h"

ASpacecraft::ASpacecraft()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpacecraft::BeginPlay()
{
	Super::BeginPlay();

	FindSubsystems();
}

void ASpacecraft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdatePower(DeltaTime);
}

UPowerGenerator* ASpacecraft::GetPowerGenerator()
{
	return PowerGenerator;
}
	
UAccumulators* ASpacecraft::GetAccumulators()
{
	return Accumulators;
}

UOxygenGenerator* ASpacecraft::GetOxygenGenerator()
{
	return OxygenGenerator;
}

UGravityGenerator* ASpacecraft::GetGravityGenerator()
{
	return GravityGenerator;
}

UShields* ASpacecraft::GetShields()
{
	return Shields;
}

UEngines* ASpacecraft::GetEngines()
{
	return Engines;
}

ASpacecraftSubsystem* ASpacecraft::GetPowerGeneratorSubsystem()
{
	return PowerGeneratorSubsystem;
}

ASpacecraftSubsystem* ASpacecraft::GetAccumulatorsSubsystem()
{
	return AccumulatorsSubsystem;
}

ASpacecraftSubsystem* ASpacecraft::GetOxygenGeneratorSubsystem()
{
	return OxygenGeneratorSubsystem;
}

ASpacecraftSubsystem* ASpacecraft::GetGravityGeneratorSubsystem()
{
	return GravityGeneratorSubsystem;
}

ASpacecraftSubsystem* ASpacecraft::GetShieldsSubsystem()
{
	return ShieldsSubsystem;
}

ASpacecraftSubsystem* ASpacecraft::GetEnginesSubsystem()
{
	return EnginesSubsystem;
}

TArray<ASpacecraftSubsystem*> ASpacecraft::GetSubsystems()
{
	return Subsystems;
}

float ASpacecraft::GetCurrentEnergyLevel()
{
	if(auto Acc = GetAccumulators())
	{
		return Acc->GetCurrentEnergyLevel();
	}
	else
	{
		return 0.f;
	}
}

float ASpacecraft::GetMaxEnergyLevel()
{
	if(auto Acc = GetAccumulators())
	{
		return Acc->GetMaxEnergyLevel();
	}
	else
	{
		return 0.f;
	}
}

float ASpacecraft::GetEnergyPercentage()
{
	if(auto Acc = GetAccumulators())
	{
		return Acc->GetEnergyPercentage();
	}
	else
	{
		return 0.f;
	}
}

float ASpacecraft::GetPowerGain()
{
	if(auto PowGen = GetPowerGenerator())
	{
		return PowGen->GetPowerOutput();
	}
	else
	{
		return 0.f;
	}
}

float ASpacecraft::GetPowerUsage()
{
	float TotalPowerUsage = 0.f;
	for(auto Subsystem : GetSubsystems())
	{
		if(Subsystem->IsFunctional())
		{
			TotalPowerUsage += Subsystem->GetPowerUsage();
		}
	}
	return TotalPowerUsage;
}

float ASpacecraft::GetPowerBalance()
{
	return GetPowerGain() - GetPowerUsage();
}

int32 ASpacecraft::GetCurrentOxygenLevel()
{
	return CurrentOxygenLevel;
}

int32 ASpacecraft::GetMaxOxygenLevel()
{
	return MaxOxygenLevel;
}

bool ASpacecraft::HasGravityEnabled()
{
	return GravityGeneratorSubsystem->IsFunctional();
}

int32 ASpacecraft::GetShieldsLevel()
{
	return GetShields()->GetCurrentShieldsLevel();
}

bool ASpacecraft::HasEnginesRunning()
{
	return EnginesSubsystem->IsFunctional();
}

void ASpacecraft::FindSubsystems()
{
	TArray<AActor*> OutActors;
	GetAttachedActors(OutActors);
	for(auto Child : OutActors)
	{
		if(ASpacecraftSubsystem* PotentialSubsystem = Cast<ASpacecraftSubsystem>(Child))
		{
			AddSubsystem(PotentialSubsystem);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Found %d subsystems for spacecraft %s"), GetSubsystems().Num(), *GetActorNameOrLabel());
}

void ASpacecraft::AddSubsystem(ASpacecraftSubsystem* Subsystem)
{
	Subsystems.Emplace(Subsystem);
	
	if(UPowerGenerator* PotentialPowerGenerator = Subsystem->FindComponentByClass<UPowerGenerator>())
	{
		PowerGenerator = PotentialPowerGenerator;
		PowerGeneratorSubsystem = Subsystem;
	}
	else if(UAccumulators* PotentialAccumulators = Subsystem->FindComponentByClass<UAccumulators>())
	{
		Accumulators = PotentialAccumulators;
		AccumulatorsSubsystem = Subsystem;
	}
	else if(UOxygenGenerator* PotentialOxygenGenerator = Subsystem->FindComponentByClass<UOxygenGenerator>())
	{
		OxygenGenerator = PotentialOxygenGenerator;
		OxygenGeneratorSubsystem = Subsystem;
	}
	else if(UGravityGenerator* PotentialGravityGenerator = Subsystem->FindComponentByClass<UGravityGenerator>())
	{
		GravityGenerator = PotentialGravityGenerator;
		GravityGeneratorSubsystem = Subsystem;
	}
	else if(UShields* PotentialShields = Subsystem->FindComponentByClass<UShields>())
	{
		Shields = PotentialShields;
		ShieldsSubsystem = Subsystem;
	}
	else if(UEngines* PotentialEngines = Subsystem->FindComponentByClass<UEngines>())
	{
		Engines = PotentialEngines;
		EnginesSubsystem = Subsystem;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast subsystem to any subsystem type"));
	}
}

void ASpacecraft::PowerOnSubsystems()
{
	for(auto Subsystem : GetSubsystems())
	{
		if(!Subsystem->IsBroken() && !Subsystem->IsPowered())
		{
			if(GetPowerBalance() >= Subsystem->GetPowerUsage())
			{
				Subsystem->PowerOn();
			}
		}
	}
}

void ASpacecraft::PowerOffSubsystems()
{
	for(auto Subsystem : GetSubsystems())
	{
		if(GetPowerBalance() > 0) return;
		if(Subsystem->IsFunctional() && Subsystem->GetPowerUsage() > 0)
		{
			Subsystem->PowerOff();
		}
	}
}

bool ASpacecraft::HasAllSubsystemsFunctional()
{
	for(auto Subsystem : GetSubsystems())
	{
		if(!Subsystem->IsFunctional())
		{
			return false;
		}
	}
	return true;
}

bool ASpacecraft::HasSomeSubsystemsFunctional()
{
	for(auto Subsystem : GetSubsystems())
	{
		if(Subsystem->IsFunctional())
		{
			return true;
		}
	}
	return false;
}

void ASpacecraft::UpdatePower(float DeltaTime)
{
	if(GetPowerBalance() < 0)
	{
		if(GetCurrentEnergyLevel() > 0)
		{
			if(auto Acc = GetAccumulators())
			{
				Acc->Discharge(-GetPowerBalance(), DeltaTime);
			}
		}
		else if(HasSomeSubsystemsFunctional())
		{
			PowerOffSubsystems();
		}
	}
	else
	{
		if(!HasAllSubsystemsFunctional())
		{
			PowerOnSubsystems();
		}
		if(GetCurrentEnergyLevel() < GetMaxEnergyLevel())
		{
			if(auto Acc = GetAccumulators())
			{
				Acc->Charge(GetPowerBalance(), DeltaTime);
			}
		}
	}
}
