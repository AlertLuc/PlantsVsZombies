// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantsBullet.h"
#include "Zombies2DCharacter.h"

void APlantsBullet::SetAttacking(const int PlantAttacking)
{
	Attacking = PlantAttacking;
}

void APlantsBullet::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(AZombies2DCharacter* Zombies2DCharacter = Cast<AZombies2DCharacter>(OtherActor))
	{
		OnHitZombies(Zombies2DCharacter);
	}


	Super::NotifyActorBeginOverlap(OtherActor);
}

void APlantsBullet::OnHitZombies(AZombies2DCharacter* Zombie)
{
	Zombie->HandlePlantsAttack(Attacking);
}
