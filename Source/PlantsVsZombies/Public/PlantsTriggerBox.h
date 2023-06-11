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


	/* ��д���� */

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

private:


	/* �¼����� */

	DECLARE_EVENT_OneParam(APlants2DCharacter, CanAttackZombies, bool)
	CanAttackZombies CanAttackZombiesEvent;
};
