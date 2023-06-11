// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Plants2DCharacter.generated.h"

class AZombies2DCharacter;

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API APlants2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
public:


	/* 属性 */

	// 生命值
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Health = 10;

	// 攻击力
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Attacking = 1;

	// 攻击速度
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int AttackSpeed = 1;

	// 是否有攻击行为
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool bPlantsAttacking = false;


	/* 重写函数 */

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	/* 事件 */

	UFUNCTION(BlueprintCallable, Category = "Plants")
	void OnPlantsDie(bool IsDie);

	UFUNCTION(BlueprintNativeEvent, Category = "Plants")
	void OnPlantsAttacking();

	virtual void OnPlantsAttacking_Implementation();

	void HandleZombiesEat(int Attacking);

	void HandleCanAttackZombies(bool CanAttack);

	/* 定时事件 */

	void TickPlantsAttacking();


	/* 事件Handle */

	FDelegateHandle CanAttackZombiesDelegateHandle;
private:


	/* 定时器 */

	FTimerHandle TickPlantsAttackingTimer;


	/* 内部状态 */

	bool bPlantCanAttacking = false;



};
