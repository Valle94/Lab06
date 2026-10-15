// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MoverActor)
	{
		Mover = MoverActor->FindComponentByClass<UMover>();

		if (Mover)
		{
			UE_LOG(LogTemp, Display, TEXT("Successfully found Mover component."));
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("Failed to find Mover component."))
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("MoverActer is not set."))
	}

	if (IsPressurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Mover)
	{
		UE_LOG(LogTemp, Display, TEXT("Trigger Activated!"))
		Mover->ShouldMove = true;
		Mover->ShouldRotate = true;
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Mover)
	{
		UE_LOG(LogTemp, Display, TEXT("Trigger Deactivated!"))
		Mover->ShouldMove = false;
		Mover->ShouldRotate = false;
	}
}
