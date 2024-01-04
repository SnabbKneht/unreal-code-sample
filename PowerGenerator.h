// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpacecraftSubsystem.h"
#include "PowerGenerator.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API UPowerGenerator : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UPowerGenerator();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetPowerOutput();

protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
	float PowerOutput;
};
