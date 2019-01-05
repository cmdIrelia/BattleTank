// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	//ִ�и����BeginPlay����

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller NOT acquried."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller acquried: %s"), *(ControlledTank->GetName()));
	}
}

ATank *ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
