// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "DrawDebugHelpers.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	//执行父类的BeginPlay函数

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
	//	DrawDebugLine(
	//		GetWorld(),
	//		PlayerCameraManager->GetCameraLocation(),
	//		hitLocation-50,
	//		FColor(255, 0, 0),
	//		false,
	//		0,
	//		0,
	//		10
	//	);
		UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *hitLocation.ToString());
		// if it hits the landscape, aim at it
	}

}

// get world location linetrack through crosshair, return true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the corsshair position in pixel coordinates 将瞄准点从UI转换到像素点位置
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	auto screenLocation = FVector2D(viewportSizeX*CorsshairXLocation, viewportSizeY*CorsshairYLocation);

	//UE_LOG(LogTemp, Warning, TEXT("screen location: %s"), *screenLocation.ToString());

	//"De-project" the screen position of the crosshair to a world direction 从屏幕反向投影到世界方向
	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("look location: %s"), *lookDirection.ToString());
		//Line trace along the look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(lookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
	FVector cameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector &hitDirection) const
{
	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * LineTrackRange);

	bool hit = GetWorld()->LineTraceSingleByChannel(
		hitResult,
		startLocation,
		endLocation,
		ECollisionChannel::ECC_Visibility);
	if (hit)
	{
		//set hit location
		hitDirection = hitResult.Location;
		return true;
	}
	
	hitDirection = FVector(0);
	return false;
}
