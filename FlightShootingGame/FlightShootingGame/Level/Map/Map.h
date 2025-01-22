#pragma once
#include "Engine/Engine.h"
#include "Level/Level.h"


class Actor;
class Map : public Level
{
	// RTTI ����.
	RTTI_DECLARATIONS(Level, RTTI)
public:

	Map();
	virtual ~Map();

	void Draw() override;
	void Update(float deltaTime) override;

private:
	// ScreenSize�� �����ϴ� ����.
	const int screenX;
	const int screenY;


	Actor* mapBuffer;		// ���� ũ�⸸ŭ ���� ��Ҹ� �����ϴ� �迭.
	Actor* screenBuffer;	// ȭ���� ũ�⸸ŭ ���� ��Ҹ� ������ �迭.
};