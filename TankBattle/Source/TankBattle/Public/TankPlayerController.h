// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:

ATank* GetControlledTank() const;

virtual void Tick(float DeltaTime) override;

virtual void BeginPlay() override;

void Aim();

bool GetHitLocation(FVector& HitLocation) const;

bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDiorection) const;

bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

UPROPERTY(EditAnywhere)
float CrosshairXLocation = 0.5;

UPROPERTY(EditAnywhere)
float CrosshairYLocation = 0.3333;

UPROPERTY(EditAnywhere)
float LinetraceRange = 1000000;




};