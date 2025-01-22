#pragma once

#include "Actor.h"
class Vector2;
class ENGINE_API DrawableActor : public Actor
{
	// RTTI.
	RTTI_DECLARATIONS(DrawableActor, Actor)

public:
	DrawableActor(const char* image = "");
	//virtual ~DrawableActor() = default;
	virtual ~DrawableActor();

	virtual void Draw() override;
	virtual void SetPosition(const Vector2& newPosition) override;

	// ���� ��ǥ�� ��ȯ�ϴ� �Լ�.
	Vector2 GetWorldPosition() const { return worldPosition; };
	// ���� ��ǥ�� �����ϴ� �Լ�.
	void SetWorldPosition(int x, int y);
	void SetWorldPosition(const Vector2& newPosition);
	void printABC();

	// �浹 Ȯ�� �Լ�.
	bool Intersect(const DrawableActor& other);
	bool aabb(const DrawableActor& other);

	// Getter.
	inline int Width() const { return width; }

protected:
	// ���� ��ǥ�� �����ϴ� ����.
	Vector2 worldPosition;


	// ȭ�鿡 �׸� ���� ��.
	char* image;

	// �ʺ�(���ڿ� ����).
	int width = 0;

	// ���� ��.
	Color color = Color::White;
	// aabb�� ���� min max
	int maxX = 0;
	int maxY = 0;

};