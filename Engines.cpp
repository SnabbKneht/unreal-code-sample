// Fill out your copyright notice in the Description page of Project Settings.

#include "Engines.h"

UEngines::UEngines()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UEngines::BeginPlay()
{
	Super::BeginPlay();
}

void UEngines::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
