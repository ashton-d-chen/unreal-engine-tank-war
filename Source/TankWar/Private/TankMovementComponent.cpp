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

void UTankMovementComponent::IntendMoveStraight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
	Lefttrack->SetThrottle(Throw);
	Righttrack->SetThrottle(Throw);
	// TODO prevent double speed 
}

void UTankMovementComponent::IntendTurn(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move left throw: %f"), Throw);
	Lefttrack->SetThrottle(-1 * Throw);
	Righttrack->SetThrottle(Throw);
}
