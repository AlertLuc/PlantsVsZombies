// Fill out your copyright notice in the Description page of Project Settings.


#include "Pea2DCharacter.h"
#include "PlantsBullet2DCharacter.h"
#include "Components/ArrowComponent.h"

void APea2DCharacter::OnPlantsAttacking_Implementation()
{
	if(!BeanPaperZDCharacterClass->IsAsset())
		return;

	if(APlantsBullet2DCharacter* BulletActor = GWorld->SpawnActor<APlantsBullet2DCharacter>(*BeanPaperZDCharacterClass,
		GetArrowComponent()->GetComponentLocation(),
		{ 0.,0.,-90. }))
	{
		BulletActor->SetActorRotation({ 0.,0.,-90. });
		BulletActor->SetAttacking(Attacking);
	}
	Super::OnPlantsAttacking_Implementation();
}
