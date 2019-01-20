// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"



//��һ��������ٶȣ�RelativeSpeed��-1��1֮�䡣
void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = this->RelativeRotation.Yaw + RotationChange;
	//NewRotation = FMath::Clamp<float>(NewRotation, this->MinRotationDegree, this->MaxRotationDegree);
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
