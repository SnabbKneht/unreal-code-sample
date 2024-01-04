// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerGenerator.h"

UPowerGenerator::UPowerGenerator()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPowerGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void UPowerGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UPowerGenerator::GetPowerOutput()
{
	return PowerOutput;
}
