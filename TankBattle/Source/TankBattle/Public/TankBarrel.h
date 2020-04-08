// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * CANNONEEEEEEEEE
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	public:
	void Elevate (float RelativeSpeed);

	private:
	UPROPERTY (EditAnywhere)
	float MaxDegreesPerSecond = 5;

	UPROPERTY (EditAnywhere)
	float MaxElevation = 40;

	UPROPERTY (EditAnywhere)
	float MinElevation = 0;
	





};
