// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBattle.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //UE_LOG(LogTemp, Error, TEXT("AAAAAAAAAAAAAAAAAAAAA"));

    Aim();


}

void ATankPlayerController::BeginPlay() 
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG (LogTemp,Error, TEXT("PlayerController NOT Posses"));
    }
    else
    {
        UE_LOG (LogTemp,Error, TEXT("PlayerController Posessing %s"), *ControlledTank->GetName());
    }
    
    
    
}


ATank* ATankPlayerController::GetControlledTank() const
{
   return Cast<ATank>(GetPawn());
   
}


void ATankPlayerController::Aim()
{
    if (!GetControlledTank()) { return; }

    FVector HitLocation;
    if (GetHitLocation(HitLocation))
    {
       //UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
        GetControlledTank()->AimAt(HitLocation);
        
    }

    
}


bool ATankPlayerController:: GetHitLocation(FVector& HitLocation) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    FVector LookDirection;

    if (GetLookDirection(ScreenLocation,LookDirection))
    {
        GetLookVectorHitLocation(LookDirection, HitLocation);
    }
 
    
    return true;
}  


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LinetraceRange);
       
        if (GetWorld()->LineTraceSingleByChannel(
                HitResult,
                StartLocation,
                EndLocation,
                ECollisionChannel::ECC_Visibility)
            )
        {
            HitLocation = HitResult.Location;
            return true;
        }
        HitLocation = FVector(0);
        return false;
}
 
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDiorection) const
{
    FVector CameraWorldLocation;
    
    return DeprojectScreenPositionToWorld(
           ScreenLocation.X,
           ScreenLocation.Y,
           CameraWorldLocation,
           LookDiorection);

    
}


