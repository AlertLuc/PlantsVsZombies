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


	/* ���� */

	// ����ֵ
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Health = 10;

	// ������
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int Attacking = 1;

	// �����ٶ�
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int AttackSpeed = 1;

	// �Ƿ��й�����Ϊ
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool bPlantsAttacking = false;


	/* ��д���� */

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	/* �¼� */

	UFUNCTION(BlueprintCallable, Category = "Plants")
	void OnPlantsDie(bool IsDie);

	UFUNCTION(BlueprintNativeEvent, Category = "Plants")
	void OnPlantsAttacking();

	virtual void OnPlantsAttacking_Implementation();

	void HandleZombiesEat(int Attacking);

	void HandleCanAttackZombies(bool CanAttack);

	/* ��ʱ�¼� */

	void TickPlantsAttacking();


	/* �¼�Handle */

	FDelegateHandle CanAttackZombiesDelegateHandle;
private:


	/* ��ʱ�� */

	FTimerHandle TickPlantsAttackingTimer;


	/* �ڲ�״̬ */

	bool bPlantCanAttacking = false;



};
