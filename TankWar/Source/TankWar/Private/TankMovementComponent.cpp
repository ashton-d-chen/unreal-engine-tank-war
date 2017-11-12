// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
}

void UTankMovementComponent::IntendMoveBack(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move backward throw: %f"), Throw);
}

void UTankMovementComponent::IntendMoveLeft(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move left throw: %f"), Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move right throw: %f"), Throw);
}

