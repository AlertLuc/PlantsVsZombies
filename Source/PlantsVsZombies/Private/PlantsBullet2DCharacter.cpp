// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantsBullet2DCharacter.h"
#include "Zombies2DCharacter.h"

void APlantsBullet2DCharacter::SetAttacking(const int PlantAttacking)
{
	Attacking = PlantAttacking;
}

void APlantsBullet2DCharacter::Move()
{
	AddMovementInput(GetActorForwardVector());
}

void APlantsBullet2DCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(!bIsHit)
	{
		Move();
	}
}

void APlantsBullet2DCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlantsBullet2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AZombies2DCharacter* Zombies2DCharacter = Cast<AZombies2DCharacter>(OtherActor))
	{
		OnHitZombies(Zombies2DCharacter);
	}


	Super::NotifyActorBeginOverlap(OtherActor);
}

void APlantsBullet2DCharacter::OnHitZombies(AZombies2DCharacter* Zombie)
{
	Zombie->HandlePlantsAttack(Attacking);
}