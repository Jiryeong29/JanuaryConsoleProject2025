#pragma once
#include "Level/Level.h"
#include "Level/MenuItem.h"
#include "Math/Vector2.h"
#include "Container/List.h"

// �� ������.
//const int XMAX = 360;
//const int YMAX = 90;


class Player;
// ToDo : ���ӷ����� player�� �������� �ʿ��� screenSize��ŭ ȭ���� ���� ������ Update���� Player�� ��ġ ������ ��� �˰� �־�� ��
class GameLevel : public Level
{

	RTTI_DECLARATIONS(GameLevel, Level)
		friend class Enemy;
public:
	GameLevel();
	virtual ~GameLevel();

	void Draw() override;
	void Update(float deltaTime) override;

	Vector2 GetMapSize() { return mapSize; }

private:
	Vector2 mapSize;
	Vector2 screenSize;
	Player* player;

private:

};