// Fill out your copyright notice in the Description page of Project Settings.

#include "GravityGenerator.h"

UGravityGenerator::UGravityGenerator()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGravityGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void UGravityGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
