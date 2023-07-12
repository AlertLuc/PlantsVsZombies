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
	FVector StandardizeToGrid(const FVector& Position) const;

	UFUNCTION(BlueprintCallable)
	void SpwanZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass)const;

	UFUNCTION(BlueprintCallable)
	void SpawnZombies();


	UFUNCTION(BlueprintCallable)
	static APvzSceneManage* GetSingletonObjectIns();

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	inline static APvzSceneManage* SingletonObject = nullptr;

	FTimerHandle SpawnZombiesTimer{};

	const double XAxis[9] = {
	-385., -325., -265., -205., -145., -85., -25., 45., 105.
	};
	const double YAxis[5] = {
		-155., -75., 15., 95., 175.
	};

	const double ZombiesSpawnX = 420.;
};
