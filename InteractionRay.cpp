// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionRay.h"
#include "Interactable.h"
#include "Kismet/KismetSystemLibrary.h"

UInteractionRay::UInteractionRay()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionRay::BeginPlay()
{
	Super::BeginPlay();

	InitializePlayerController();
}

void UInteractionRay::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DisplayWidgetIfNeeded();
}

IInteractable* UInteractionRay::GetInteractableActorOrComponent()
{
	auto HitResult = GetHitResult();

	if(auto HitActor = HitResult.GetActor())
	{
		// try actor
		if(auto InteractableActor = Cast<IInteractable>(HitActor))
		{
			return InteractableActor;
		}
		
		// try component
		auto InteractableComponent = HitActor->FindComponentByInterface<UInteractable>();
		if(IInteractable* CastedComponent = Cast<IInteractable>(InteractableComponent))
		{
			return CastedComponent;
		}
	}
	
	return nullptr;
}

void UInteractionRay::DisplayWidgetIfNeeded()
{
	IInteractable* NewTarget = GetInteractableActorOrComponent();
	if(NewTarget != CurrentTarget)
	{
		if(NewTarget)
		{
			NewTarget->Execute_DisplayWidget(Cast<UObject>(NewTarget), PlayerController);
		}
		if(CurrentTarget)
		{
			CurrentTarget->Execute_HideWidget(Cast<UObject>(CurrentTarget), PlayerController);
		}
	}
	CurrentTarget = NewTarget;
}

void UInteractionRay::InitializePlayerController()
{
	PlayerController = Cast<APlayerController>(Cast<APawn>(GetAttachParentActor())->GetController());
	if(PlayerController)
	{
		UE_LOG(LogTemp, Display, TEXT("Player controller initialized successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to initialize player controller"));
	}
}

FHitResult UInteractionRay::GetHitResult()
{
	FHitResult HitResult;
	FVector Start = GetComponentLocation();
	FVector End = GetComponentLocation() + GetForwardVector() * RayLength;
	GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_GameTraceChannel2);
	return HitResult;
}
