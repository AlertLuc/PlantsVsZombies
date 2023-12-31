// Fill out your copyright notice in the Description page of Project Settings.


#include "Plants2DCharacter.h"

#include "UPVZSceneManage.h"


void APlants2DCharacter::BeginPlay()
{
	// ����ֲ�﹥����Ƶ��
	GetWorld()->GetTimerManager().SetTimer(TickPlantsAttackingTimer, this, &APlants2DCharacter::TickPlantsAttacking, 1.0f / AttackSpeed, true);
	Super::BeginPlay();
}

void APlants2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// �����ʱ��
	GetWorld()->GetTimerManager().ClearTimer(TickPlantsAttackingTimer);
	Super::EndPlay(EndPlayReason);
}

// ����ֲ������λ��
void APlants2DCharacter::SetGrowGrid(int GridX, int GridY)
{
	GrowX = GridX;
	GrowY = GridY;
}

// ֲ������
void APlants2DCharacter::OnPlantsDie(bool IsDie)
{
	if (IsDie) {
		APvzSceneManage::GetInstance()->RemovePlant(GrowX, GrowY);
		Destroy();
	}
}

void APlants2DCharacter::OnPlantsAttacking_Implementation()
{

}

// ֲ�ﱻ��ʬ�Ե�
void APlants2DCharacter::HandleZombiesEat(const int ZombiesAttacking)
{
	Health -= ZombiesAttacking;
	if (Health <= 0) 
	{
		OnPlantsDie(true);
	}
}

// ֲ���Ƿ񹥻���ʬ
void APlants2DCharacter::HandleCanAttackZombies(const bool CanAttack)
{
	bPlantCanAttacking = CanAttack;
}

// ���ֲ�ﱻ����
void APlants2DCharacter::TickPlantsAttacking()
{
	if (bPlantsAttacking && bPlantCanAttacking)
		OnPlantsAttacking();

}
