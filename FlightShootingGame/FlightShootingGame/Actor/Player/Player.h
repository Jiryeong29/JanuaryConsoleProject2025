#pragma once
#include "Actor/DrawableActor.h"
class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)
	
	// Todo : Enemy�� friend�� ����� �� ������? getter setter�� ���� enemy�� ������ �� �ְ� ���ִ� ���� ������??
	// �ϴ��� ���ϴ� friend�� �ϰ���
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
	//// �� ��ǥ
	//Vector2 absoluteCoordinates;

};