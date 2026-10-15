// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LAB06_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	UPROPERTY(EditAnywhere)
	FRotator RotateOffset;

	UPROPERTY(EditAnywhere)
	float MoveTime = 4.0f;

	UPROPERTY(EditAnywhere)
	bool ShouldMove;

	UPROPERTY(EditAnywhere)
	bool ShouldRotate;

	FVector StartLocation;
	FVector TargetLocation;

	FRotator StartRotation;
	FRotator TargetRotation;
};
