#include "UPVZSceneManage.h"


FVector APvzSceneManage::CheckPlantGrid(const FVector& Position, UPARAM(ref) bool& IsGrow, UPARAM(ref) int& IndexX, UPARAM(ref) int& IndexY) const
{
	int i = -1, j = -1;
	for (auto k = size_t(); k < std::size(XAxis); ++k) 
	{
		if(UKismetMathLibrary::NearlyEqual_FloatFloat(Position.X, XAxis[k], 40.))
		{
			i = k;
			break;
		}
	}
	for (auto k = size_t(); k < std::size(YAxis); ++k) {
		if (UKismetMathLibrary::NearlyEqual_FloatFloat(Position.Y, YAxis[k], 50.))
		{
			j = k;
			break;
		}
	}
	if (i == -1 || j == -1)
	{
		IsGrow = false;
		return {};
	}
	if(HavePlants[i][j])
	{
		IsGrow = false;
		return {};
	}
	IsGrow = true;
	IndexX = i;
	IndexY = j;
	return { XAxis[i], YAxis[j], 10. };
}

void APvzSceneManage::GrowPlant(int IndexX, int IndexY)
{
	HavePlants[IndexX][IndexY] = true;
}

void APvzSceneManage::RemovePlant(int IndexX, int IndexY)
{
	HavePlants[IndexX][IndexY] = false;
}

void APvzSceneManage::SpwanZombiesType(const TSubclassOf<AZombies2DCharacter> ZombiesPaperZDCharacterClass) const
{
	const auto SpawnYAxis = UKismetMathLibrary::RandomIntegerInRange(0, std::size(YAxis));
	const FVector SpwanPosition{ ZombiesSpawnX,YAxis[SpawnYAxis],10. };

	if (const AZombies2DCharacter* ZombiesActor = GWorld->SpawnActor<AZombies2DCharacter>(*ZombiesPaperZDCharacterClass,
		SpwanPosition,
		{ 0.,0.,-90. }); ZombiesActor)
	{
	}


}

void APvzSceneManage::SpawnZombies()
{
	if(UKismetMathLibrary::RandomIntegerInRange(0 , 100) >= 60)
		return;

	if(ZombiesPaperZDCharacterClassArray.IsEmpty())
		return;

	const auto ZombiesType = UKismetMathLibrary::RandomIntegerInRange(0, ZombiesPaperZDCharacterClassArray.Num());
	SpwanZombiesType(ZombiesPaperZDCharacterClassArray[ZombiesType]);
}

APvzSceneManage* APvzSceneManage::GetInstance() {
	if (GEngine)
	{
		APvzSceneManage* Instance = Cast<APvzSceneManage>(GEngine->GameSingleton);
		return Instance;
	}
	return nullptr;
}

void APvzSceneManage::BeginPlay()
{
	GWorld->GetTimerManager().SetTimer(SpawnZombiesTimer, this, &APvzSceneManage::SpawnZombies, 5, true);
}

void APvzSceneManage::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GWorld->GetTimerManager().ClearTimer(SpawnZombiesTimer);
}

