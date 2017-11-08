// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time

//	auto Time = GetWorld()->GetTimeSeconds();
//	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed of %f"), RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegressesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto RawNewelevation = RelativeRotation.Pitch + ElevationChange;

	auto elevation = FMath::Clamp<float>(RawNewelevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(elevation, 0, 0));

}


