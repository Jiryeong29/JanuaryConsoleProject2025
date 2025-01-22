#pragma once
#include "Engine/Engine.h"
#include "Level/Level.h"


class Actor;
class Map : public Level
{
	// RTTI 정의.
	RTTI_DECLARATIONS(Level, RTTI)
public:

	Map();
	virtual ~Map();

	void Draw() override;
	void Update(float deltaTime) override;

private:
	// ScreenSize를 저장하는 변수.
	const int screenX;
	const int screenY;


	Actor* mapBuffer;		// 맵의 크기만큼 맵의 요소를 저장하는 배열.
	Actor* screenBuffer;	// 화면의 크기만큼 맵의 요소를 저장할 배열.
};