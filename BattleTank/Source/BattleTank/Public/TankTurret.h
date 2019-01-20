// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
//hideCategories��ʾ��BP��detail�е�ĳЩ��������ء��ò����ѡ��
//ClassGroup = (Custom),
/* �Զ���һ��Component���ɱ���ͼ���� */
UCLASS(meta = (BlueprintSpawnableComponent))//, hideCategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 30;

	//UPROPERTY(EditAnywhere, Category = Setup)
	//	float MaxRotationDegree = 40;

	//UPROPERTY(EditAnywhere, Category = Setup)
	//	float MinRotationDegree = 0;
	
};
