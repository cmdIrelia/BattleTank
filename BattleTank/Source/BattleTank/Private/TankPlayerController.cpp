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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank *ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector hitLocation;	//out parameter

	if (GetSightRayHitLocation(hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *hitLocation.ToString());
		// if it hits the landscape, aim at it
	}

}

// get world location linetrack through crosshair, return true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the corsshair position in pixel coordinates ����׼���UIת�������ص�λ��
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	auto screenLocation = FVector2D(viewportSizeX*CorsshairXLocation, viewportSizeY*CorsshairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("screen location: %s"), *screenLocation.ToString());

	//"De-project" the screen position of the crosshair to a world direction ����Ļ����ͶӰ�����緽��
	FVector cameraWorldLocation;
	FVector worldDirection;

	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("look location: %s"), *worldDirection.ToString());
	}

	//Line trace along the look direction, and see what we hit (up to max range)
	return true;
}
