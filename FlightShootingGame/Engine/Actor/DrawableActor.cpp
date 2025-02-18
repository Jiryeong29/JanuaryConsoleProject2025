#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"
#include <cstring>      // strlen, strcpy_s
#include <sstream>      // std::stringstream
#include <string>       // std::string
#include <iostream>     // std::cout (디버깅 시 사용 가능)
#include "Math/Vector2.h"
DrawableActor::DrawableActor(const char* image)
	: Actor()/*, image(image)*/, worldPosition(Vector2(0,0))
{

	// 전달 받은 문자열 복사.
	auto length = strlen(image) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, image);
	// 가로 길이 중 가장 긴 가로의 길이를 탐색
	int tmpX = 0;

	for (int i = 0; i < length;++i)
	{
		if (image[i] == '\n')
		{
			if (maxX <= tmpX)
			{
				maxX = tmpX;
			}
			++maxY;
			tmpX = 0;
		}
		else
		{
			++tmpX;
		}
	}

	if (maxY == 0)
	{
		maxX = (int)strlen(image);
	}
	else
	{
		--maxY;
	}
	
	// ToDo : 이걸  왜 해놨지?
	maxX--;
	// 너비 설정.
	width = (int)strlen(image);
}

DrawableActor::~DrawableActor()
{
	delete[] image;
}

void DrawableActor::Draw()
{
	Super::Draw();

	Engine::Get().Draw(position, image, color);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	//// 이전의 위치를 먼저 지우기.
	//Engine::Get().SetCursorPosition(position);
	//Log(" ");

	// 위치를 새로 옮기기.
	Super::SetPosition(newPosition);
}

void DrawableActor::SetWorldPosition(const int x, const int y)
{
	worldPosition.x = x;
	worldPosition.y = y;
}

void DrawableActor::SetWorldPosition(const Vector2& newPosition)
{
	worldPosition = newPosition;
}

void DrawableActor::printABC()
{
}

bool DrawableActor::Intersect(const DrawableActor& other)
{
	// AABB(Axis Aligned Bounding Box).

	// 내 x좌표 최소/최대.
	int min = position.x;
	int max = position.x + width;

	// 다른 액터의 x좌표 최소/최대.
	int otherMin = other.position.x;
	int otherMax = other.position.x + other.width;

	// 다른 액터의 왼쪽 끝 위치가 내 오른쪽 끝 위치를 벗어나면 충돌 안함.
	if (otherMin > max)
	{
		return false;
	}

	// 다른 액터의 오른쪽 끝 위치가 내 왼쪽 끝 위치보다 작으면 충돌 안함.
	if (otherMax < min)
	{
		return false;
	}

	// 위의 두 경우가 아니라면 (x좌표는 서로 겹침), y위치 비교.
	return position.y == other.position.y;
}

bool DrawableActor::aabb(const DrawableActor& other)
{// AABB (Axis Alighend Bounding Box).

 	int minX = position.x;
	int maxX = position.x + this->maxX;

	// 내 y좌표 최소/최대
	int minY = position.y;
	int maxY = position.y + this->maxY;

	// 다른 액터의 x, y 최소/최대
	int otherMinX = other.position.x;
	int otherMaxX = other.position.x + other.maxX;
	int otherMinY = other.position.y;
	int otherMaxY = other.position.y + other.maxY;

	// 충돌 여부 확인
 	return !(maxX < otherMinX || minX > otherMaxX ||
		maxY < otherMinY || minY > otherMaxY);
}
