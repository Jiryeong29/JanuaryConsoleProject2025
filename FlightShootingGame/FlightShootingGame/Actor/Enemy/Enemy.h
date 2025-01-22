#pragma once
#include "Actor/DrawableActor.h"

// ToDo: Enemy가 Player를 추격하기 때문에 Update마다 Player의 위치를 알고 있어야 함
// -> Enemy가 Player랑 has-A 관계는 말이 안되는 것 같고 friend는 괜찮지만 친구라서 쫓아감? 잘 모르겟다. 일단 Player를 싱긑톤으로 구현하는 방법으로 접근해보기

class GameLevel;
class Enemy : public DrawableActor
{
	friend class GameLevel;
	RTTI_DECLARATIONS(Enemy, DrawableActor)
	// 적 캐릭터가 이동할 방향.
	enum class SpawnPosition
	{
		None = -1,
		Left,
		Right,
		Up,
		Down
	};

public:
	Enemy(GameLevel* level);
	virtual ~Enemy();

	void SetSpawnWorldPosition();
	void Update(float deltaTime);
private:
	SpawnPosition spawnPosition = SpawnPosition::None;
	GameLevel* gameLevel;
};