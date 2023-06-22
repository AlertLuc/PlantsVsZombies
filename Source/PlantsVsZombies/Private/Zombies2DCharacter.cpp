// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombies2DCharacter.h"
#include "Plants2DCharacter.h"

void AZombies2DCharacter::BeginPlay()
{
	GetWorld()->GetTimerManager().SetTimer(TickZombiesEatTimer, this, &AZombies2DCharacter::TickZombiesEat, 1.0f / AttackSpeed, true);
	Super::BeginPlay();
}

void AZombies2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(TickZombiesEatTimer);
	Super::EndPlay(EndPlayReason);
}

void AZombies2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		OnZombiesOverlapPlants(Plants2DCharacter, true);
	}
}

void AZombies2DCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	if (APlants2DCharacter* Plants2DCharacter = Cast<APlants2DCharacter>(OtherActor))
	{
		OnZombiesOverlapPlants(Plants2DCharacter, false);
	}
}

void AZombies2DCharacter::OnZombiesOverlapPlants(APlants2DCharacter* Plants2DCharacter, bool Overlap)
{
	// �����ص�״̬
	bZombiesOverlapPlants = Overlap;
	// ���Ŷ���
	OnZombiesEat(bZombiesOverlapPlants);
	// ע���¼�
	ZombiesEatEvent.AddUObject(Plants2DCharacter, &APlants2DCharacter::HandleZombiesEat);
}

void AZombies2DCharacter::HandlePlantsAttack(const int PlantsAttacking)
{
	Health -= PlantsAttacking;
	if (Health <= 0)
	{
		OnZombiesDie(true);
	}
}

void AZombies2DCharacter::TickZombiesEat() const
{
	if (bZombiesOverlapPlants)
		ZombiesEatEvent.Broadcast(Attacking);
}

void AZombies2DCharacter::Move()
{
}