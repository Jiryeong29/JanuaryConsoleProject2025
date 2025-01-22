#pragma once
#include "Level/Level.h"
#include "Level/MenuItem.h"
#include "Math/Vector2.h"
#include "Container/List.h"

// 맵 사이즈.
//const int XMAX = 360;
//const int YMAX = 90;


class Player;
// ToDo : 게임레벨은 player를 기준으로 맵에서 screenSize만큼 화면을 띄우기 떄문에 Update마다 Player의 위치 정보를 계속 알고 있어야 함
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