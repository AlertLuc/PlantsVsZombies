// Fill out your copyright notice in the Description page of Project Settings.


#include "Plants2DCharacter.h"


void APlants2DCharacter::BeginPlay()
{
	GetWorld()->GetTimerManager().SetTimer(TickPlantsAttackingTimer, this, &APlants2DCharacter::TickPlantsAttacking, 1.0f / AttackSpeed, true);
	Super::BeginPlay();
}

void APlants2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(TickPlantsAttackingTimer);
	Super::EndPlay(EndPlayReason);
}

void APlants2DCharacter::OnPlantsDie(bool IsDie)
{
	if (IsDie)
		Destroy();
}

void APlants2DCharacter::OnPlantsAttacking_Implementation()
{
}

void APlants2DCharacter::HandleZombiesEat(const int ZombiesAttacking)
{
	Health -= ZombiesAttacking;
	if (Health <= 0) 
	{
		OnPlantsDie(true);
	}
}

void APlants2DCharacter::HandleCanAttackZombies(const bool CanAttack)
{
	bPlantCanAttacking = CanAttack;
}

void APlants2DCharacter::TickPlantsAttacking()
{
	if (bPlantsAttacking && bPlantCanAttacking)
		OnPlantsAttacking();

}
