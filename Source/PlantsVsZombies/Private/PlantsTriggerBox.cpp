// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantsTriggerBox.h"
#include "Plants2DCharacter.h"
#include "Zombies2DCharacter.h"

void APlantsTriggerBox::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		// ע���¼�
		Plants2DCharacter->CanAttackZombiesDelegateHandle = CanAttackZombiesEvent.AddUObject(Plants2DCharacter, &APlants2DCharacter::HandleCanAttackZombies);
	}
	if(Cast<AZombies2DCharacter>(OtherActor))
	{
		CanAttackZombiesEvent.Broadcast(true);
	}
	Super::NotifyActorBeginOverlap(OtherActor);
}

void APlantsTriggerBox::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (const APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		// ȡ��ע���¼�
		CanAttackZombiesEvent.Remove(Plants2DCharacter->CanAttackZombiesDelegateHandle);
	}
	if (Cast<AZombies2DCharacter>(OtherActor))
	{
		CanAttackZombiesEvent.Broadcast(false);
	}
	Super::NotifyActorEndOverlap(OtherActor);
}
