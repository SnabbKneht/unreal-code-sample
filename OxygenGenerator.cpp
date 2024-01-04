// Fill out your copyright notice in the Description page of Project Settings.

#include "OxygenGenerator.h"

UOxygenGenerator::UOxygenGenerator()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOxygenGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void UOxygenGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

int32 UOxygenGenerator::GetOxygenOutput()
{
	return OxygenOutput;
}
