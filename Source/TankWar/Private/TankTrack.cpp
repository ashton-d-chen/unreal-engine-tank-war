// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
  UE_LOG(LogTemp, Warning, TEXT("%s throttle is %f"), *Name, Throttle);

	// TODO clamp raw throttle value so player can't increase tank speed
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

