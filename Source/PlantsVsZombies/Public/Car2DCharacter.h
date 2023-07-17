// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Car2DCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSVSZOMBIES_API ACar2DCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	bool bIsRun = false;

	// ��д���� �̳���Ϸ����actor��
	virtual void Tick(float DeltaSeconds) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ��ײ���
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// �ƶ�
	UFUNCTION(BlueprintCallable)
	void Move();

	// ����
	void DestroyCar()
	{
		Destroy();
	}

private:
	/* ��ʱ�� */
	FTimerHandle CarDestroyTimer;
};
