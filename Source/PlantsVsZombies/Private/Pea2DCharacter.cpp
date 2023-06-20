// Fill out your copyright notice in the Description page of Project Settings.


#include "Pea2DCharacter.h"
#include "PlantsBullet.h"

void APea2DCharacter::OnPlantsAttacking_Implementation()
{
	if(!PeaBulletClass)
		return;

	if(APlantsBullet* BulletActor = GWorld->SpawnActor<APlantsBullet>(PeaBulletClass->GetClass(), GetActorLocation(),{-90.,0.,0.}))
	{
		BulletActor->SetAttacking(Attacking);
	}
	Super::OnPlantsAttacking_Implementation();
}
