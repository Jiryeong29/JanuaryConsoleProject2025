#include "Player.h"
#include "Engine/Engine.h"
//#include "Actor/DrawableActor.h"


Player* Player::instance = nullptr;

Player::Player(const char* playerImage)
    : Super(playerImage)
{
    //SetWorldPosition(200,60);
    // Player�� World ��ǥ �缳��.
    SetWorldPosition(Vector2(200,60));
    Vector2 PlayerPosition(static_cast<int>(Engine::Get().ScreenSize().x / 2), static_cast<int>(Engine::Get().ScreenSize().y / 2));
    SetPosition(PlayerPosition);
}
Player::~Player()
{
    //�̱��� ��ü ����
    instance = this;
}

Player& Player::Get()
{
    return *instance; 
}


void Player::Update(float deltaTime)

{
   
    Vector2 PlayerWolrdPosition = GetWorldPosition();
    // Ű �Է� ó��
    if (Engine::Get().GetKey(VK_LEFT))
    {
        --PlayerWolrdPosition.x;
    }

    if (Engine::Get().GetKey(VK_RIGHT))
    {
        ++PlayerWolrdPosition.x;
    }
    if (Engine::Get().GetKey(VK_UP))
    {
        --PlayerWolrdPosition.y;
    }
    if (Engine::Get().GetKey(VK_DOWN))
    {
        ++PlayerWolrdPosition.y;
    }

    // ���� ��ǥ ����.
    SetWorldPosition(PlayerWolrdPosition);
}
