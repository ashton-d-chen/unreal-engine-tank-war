// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}

//	UE_LOG(LogTemp, Warning, TEXT("PlayerConroller Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	UE_LOG(LogTemp, Warning, TEXT("Tick"));
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation;  // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
	//	UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *(HitLocation.ToString()));
	}
	// Get world location if linetrace through crosshair
	// If it his the landscape
	  // Tell controlled tank to turn turret.
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *(ScreenLocation.ToString()));

	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace a long that look direction, and see what we hit (up to max range)
	HitLocation = FVector(1.0);
	return true;
}

