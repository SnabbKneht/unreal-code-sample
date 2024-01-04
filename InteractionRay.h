// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InteractionRay.generated.h"

class IInteractable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEGAME_API UInteractionRay : public USceneComponent
{
	GENERATED_BODY()

public:	
	
	UInteractionRay();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float RayLength;

	APlayerController* PlayerController;

	IInteractable* CurrentTarget = nullptr;
	
	IInteractable* GetInteractableActorOrComponent();

	void DisplayWidgetIfNeeded();

	void InitializePlayerController();

	FHitResult GetHitResult();
};
