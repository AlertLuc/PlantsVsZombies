// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantsTriggerBox.h"
#include "Plants2DCharacter.h"
#include "Zombies2DCharacter.h"

void APlantsTriggerBox::NotifyPlants() const
{
	if (HaveZombiesNum > 0)
	{
		CanAttackZombiesEvent.Broadcast(true);
	}
	else
	{
		CanAttackZombiesEvent.Broadcast(false);
	}
}

void APlantsTriggerBox::NotifyZombies() const
{
	if (HavePlantsNum > 0)
	{
		CanAttackPlantsEvent.Broadcast(true);
	}
	else
	{
		CanAttackPlantsEvent.Broadcast(false);
	}
}

void APlantsTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		HavePlantsNum++;
		NotifyZombies();
		NotifyPlants();
		// 注册事件
		Plants2DCharacter->CanAttackZombiesDelegateHandle = CanAttackZombiesEvent.AddUObject(Plants2DCharacter, &APlants2DCharacter::HandleCanAttackZombies);
	}
	if(Cast<AZombies2DCharacter>(OtherActor))
	{
		HaveZombiesNum++;
		NotifyZombies();
		NotifyPlants();
	}
	Super::NotifyActorBeginOverlap(OtherActor);
}

void APlantsTriggerBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (const APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		HavePlantsNum--;
		NotifyZombies();
		NotifyPlants();
		// 取消注册事件
		CanAttackZombiesEvent.Remove(Plants2DCharacter->CanAttackZombiesDelegateHandle);
	}
	if (Cast<AZombies2DCharacter>(OtherActor))
	{
		HaveZombiesNum--;
		NotifyZombies();
		NotifyPlants();
	}
	Super::NotifyActorEndOverlap(OtherActor);
}
