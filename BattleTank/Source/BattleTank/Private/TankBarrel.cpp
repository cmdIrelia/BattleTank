// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"



//��һ��������ٶȣ�RelativeSpeed��-1��1֮�䡣
void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto elevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = this->RelativeRotation.Pitch + elevationChange;
	NewElevation = FMath::Clamp<float>(NewElevation, this->MinElevationDegree, this->MaxElevationDegree);
	SetRelativeRotation(FRotator(NewElevation, 0, 0));

}
