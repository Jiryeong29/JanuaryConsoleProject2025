#pragma once
#include "Actor/DrawableActor.h"

// ToDo: Enemy�� Player�� �߰��ϱ� ������ Update���� Player�� ��ġ�� �˰� �־�� ��
// -> Enemy�� Player�� has-A ����� ���� �ȵǴ� �� ���� friend�� �������� ģ���� �Ѿư�? �� �𸣰ٴ�. �ϴ� Player�� �̃P������ �����ϴ� ������� �����غ���

class GameLevel;
class Enemy : public DrawableActor
{
	friend class GameLevel;
	RTTI_DECLARATIONS(Enemy, DrawableActor)
	// �� ĳ���Ͱ� �̵��� ����.
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