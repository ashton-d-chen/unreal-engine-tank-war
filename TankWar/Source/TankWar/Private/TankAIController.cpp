// Fill out your copyright notice in the Description page of Project Settings.

#include "TankWar.h"
#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*
	auto const ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessed"));
	}

	auto const PlayTank = GetPlayerTank();

	if (PlayTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank acquired: %s"), *(PlayTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"));
	}
	*/
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		// Aim towards the player
		auto ControlledTank = GetControlledTank();

		if (ControlledTank)
		{
			ControlledTank->AimAt(PlayerTank->GetActorLocation());
			//ControlledTank->Fire();  // TODO limite fire rate
		}
	}
}