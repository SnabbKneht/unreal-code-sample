// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpacecraftSubsystem.h"
#include "Shields.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API UShields : public UActorComponent
{
	GENERATED_BODY()

public:

	UShields();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetCurrentShieldsLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetMaxShieldsLevel();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetShieldsPercentage();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetShieldsRestorationRate();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleInstanceOnly)
	int32 CurrentShieldsLevel;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxShieldsLevel;

	UPROPERTY(EditDefaultsOnly)
	int32 ShieldsRestorationRate;
};
