// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

//void ATankAIController::Tick(float DeltaTime)
//{
//    Super::Tick(DeltaTime);

//    UE_LOG(LogTemp, Error, TEXT("AAAAAAAAAAAAAAAAAAAAA"));


//}


void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Aim();
}


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Error, TEXT("AiController not find PT"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AiController Find %s"), *PlayerTank->GetName());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
     //return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); funziona ma meglio verificarlo subito

     auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
     
     if (!PlayerPawn) { return nullptr; }

     return Cast<ATank>(PlayerPawn);
     

}

void ATankAIController::Aim()
{
    if (!GetControlledTank()) { return; }
    
    GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

}