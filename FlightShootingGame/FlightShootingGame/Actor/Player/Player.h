#pragma once
#include "Actor/DrawableActor.h"
class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)
	
	// Todo : Enemy를 friend로 만드는 게 좋을까? getter setter를 만들어서 enemy가 접근할 수 있게 해주는 것이 좋을까??
	// 일단은 급하니 friend로 하겠음
	//friend class Enemy;
public:
	Player(const char* PlayerImage);
	~Player();

	static Player& Get();
	
	void Update(float deltaTime) override;
	
	Vector2 GetPlayerWorldPosition() { return GetWorldPosition(); }

private:
	static Player* instance;

private:
	//// 맵 좌표
	//Vector2 absoluteCoordinates;

};