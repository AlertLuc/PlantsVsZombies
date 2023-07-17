// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantsBullet2DCharacter.h"

#include "PvzFunctionLibrary.h"
#include "Zombies2DCharacter.h"

// ���÷���
void APlantsBullet2DCharacter::SetAttacking(const int PlantAttacking)
{
	Attacking = PlantAttacking;
}

// �ӵ��ƶ�
void APlantsBullet2DCharacter::Move()
{
	UPvzFunctionLibrary::MoveActor(this, GetActorForwardVector(), 1.0);
}

// �ƶ����
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

// �ӵ��򵽽�ʬ
void APlantsBullet2DCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AZombies2DCharacter* Zombies2DCharacter = Cast<AZombies2DCharacter>(OtherActor))
	{
		OnHitZombies(Zombies2DCharacter);
	}

	Super::NotifyActorBeginOverlap(OtherActor);
}

// �ӵ��򵽽�ʬ����ʬ������
void APlantsBullet2DCharacter::OnHitZombies(AZombies2DCharacter* Zombie)
{
	Zombie->HandlePlantsAttack(Attacking);
}