// Fill out your copyright notice in the Description page of Project Settings.


#include "Pea2DCharacter.h"
#include "PlantsBullet2DCharacter.h"

void APea2DCharacter::OnPlantsAttacking_Implementation()
{
	// 是否设置子弹类型
	if(!BeanPaperZDCharacterClass->IsAsset())
		return;

	// 生成子弹
	if(APlantsBullet2DCharacter* BulletActor = GWorld->SpawnActor<APlantsBullet2DCharacter>(*BeanPaperZDCharacterClass,
		GetActorLocation() + BulletSpawnPosition,
		{ 0.,0.,-90. }))
	{
		// 把植物攻击力设置到子弹上
		BulletActor->SetAttacking(Attacking);
	}
	Super::OnPlantsAttacking_Implementation();
}
