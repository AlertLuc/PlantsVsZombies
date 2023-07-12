#include "UPVZSceneManage.h"


FVector APvzSceneManage::StandardizeToGrid(const FVector& Position) const
{
	auto i = int(), j = int();
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
	return { XAxis[i],YAxis[j],10. };
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

APvzSceneManage* APvzSceneManage::GetSingletonObjectIns() {
	if (SingletonObject == nullptr) {
		SingletonObject = NewObject<APvzSceneManage>();
	}
	return SingletonObject;
}

void APvzSceneManage::BeginPlay()
{
	GWorld->GetTimerManager().SetTimer(SpawnZombiesTimer, this, &APvzSceneManage::SpawnZombies, 5, true);
}

void APvzSceneManage::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GWorld->GetTimerManager().ClearTimer(SpawnZombiesTimer);
}

