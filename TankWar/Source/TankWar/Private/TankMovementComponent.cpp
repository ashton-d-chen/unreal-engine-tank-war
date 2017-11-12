// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
	Lefttrack = LeftTrackToSet;
	Righttrack =	RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
	Lefttrack->SetThrottle(Throw);
	Righttrack->SetThrottle(Throw);
	// TODO prevent double speed 
}

void UTankMovementComponent::IntendMoveBack(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move backward throw: %f"), Throw);
	Lefttrack->SetThrottle(-1 * Throw);
	Righttrack->SetThrottle(-1 * Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move left throw: %f"), Throw);
	Lefttrack->SetThrottle(-1 * Throw);
	Righttrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move right throw: %f"), Throw);
	Lefttrack->SetThrottle(Throw);
	Righttrack->SetThrottle(-1 * Throw);
}

