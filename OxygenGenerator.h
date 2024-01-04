// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpacecraftSubsystem.h"
#include "OxygenGenerator.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API UOxygenGenerator : public UActorComponent
{
	GENERATED_BODY()

public:

	UOxygenGenerator();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetOxygenOutput();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
	int32 OxygenOutput;
};
