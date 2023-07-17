// Fill out your copyright notice in the Description page of Project Settings.


#include "Plants2DCharacter.h"

#include "UPVZSceneManage.h"


void APlants2DCharacter::BeginPlay()
{
	// 设置植物攻击的频率
	GetWorld()->GetTimerManager().SetTimer(TickPlantsAttackingTimer, this, &APlants2DCharacter::TickPlantsAttacking, 1.0f / AttackSpeed, true);
	Super::BeginPlay();
}

void APlants2DCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// 清除计时器
	GetWorld()->GetTimerManager().ClearTimer(TickPlantsAttackingTimer);
	Super::EndPlay(EndPlayReason);
}

// 设置植物生长位置
void APlants2DCharacter::SetGrowGrid(int GridX, int GridY)
{
	GrowX = GridX;
	GrowY = GridY;
}

// 植物死亡
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

// 植物被僵尸吃掉
void APlants2DCharacter::HandleZombiesEat(const int ZombiesAttacking)
{
	Health -= ZombiesAttacking;
	if (Health <= 0) 
	{
		OnPlantsDie(true);
	}
}

// 植物是否攻击僵尸
void APlants2DCharacter::HandleCanAttackZombies(const bool CanAttack)
{
	bPlantCanAttacking = CanAttack;
}

// 检测植物被攻击
void APlants2DCharacter::TickPlantsAttacking()
{
	if (bPlantsAttacking && bPlantCanAttacking)
		OnPlantsAttacking();

}
