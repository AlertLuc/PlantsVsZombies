// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PlantsTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APlantsTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:


	/* 重写函数 */

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

private:


	/* 事件声明 */

	DECLARE_EVENT_OneParam(APlants2DCharacter, CanAttackZombies, bool)
	CanAttackZombies CanAttackZombiesEvent;
};
