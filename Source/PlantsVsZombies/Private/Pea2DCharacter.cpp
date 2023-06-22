// Fill out your copyright notice in the Description page of Project Settings.


#include "Pea2DCharacter.h"
#include "PlantsBullet.h"
#include "Components/ArrowComponent.h"

void APea2DCharacter::OnPlantsAttacking_Implementation()
{
	if(!PeaBulletClass->IsAsset())
		return;

	if(APlantsBullet* BulletActor = GWorld->SpawnActor<APlantsBullet>(*PeaBulletClass, 
		GetArrowComponent()->GetComponentLocation(),
		GetArrowComponent()->GetComponentRotation()))
	{
		BulletActor->SetActorRotation({ 0.,0.,-90. });
		BulletActor->SetAttacking(Attacking);
	}
	Super::OnPlantsAttacking_Implementation();
}
