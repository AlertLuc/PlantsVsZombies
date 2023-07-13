#pragma once
#include "CoreMinimal.h"
#include "Zombies2DCharacter.h"
#include "GeometryCollection/GeometryCollectionEngineSizeSpecificUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "UPVZSceneManage.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APvzSceneManage : public AActor
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<TSubclassOf<AZombies2DCharacter>> ZombiesPaperZDCharacterClassArray;

	UFUNCTION(BlueprintCallable)
	FVector CheckPlantGrid(const FVector& Position, UPARAM(ref) bool& IsGrow, UPARAM(ref) int& IndexX, UPARAM(ref) int& IndexY)const;

	UFUNCTION(BlueprintCallable)
	void GrowPlant(int IndexX,int IndexY);

	UFUNCTION(BlueprintCallable)
	void RemovePlant(int IndexX, int IndexY);

	UFUNCTION(BlueprintCallable)
	void SpwanZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass)const;

	UFUNCTION(BlueprintCallable)
	void SpawnZombies();


	UFUNCTION(BlueprintCallable)
	static APvzSceneManage* GetInstance();

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

	FTimerHandle SpawnZombiesTimer{};

	const double XAxis[9] = {
	-410., -330., -250., -170., -90., -10., 70., 150., 230.
	};
	const double YAxis[5] = {
		-160., -60., 40., 140., 240.
	};

	bool HavePlants[9][5] = { false };

	const double ZombiesSpawnX = 420.;
};
