#include "Enemy.h"
#include "Engine/Engine.h"
#include "Actor/Player/Player.h"
#include "Level/Game/GameLevel.h"

// ToDo : enemy가 게임레벨에서 정의하는 mapSize를 알고 있어야 하는데 어떤 방식으로 알게 하면 좋을까

Enemy::Enemy(GameLevel* level)
    : gameLevel(level)
{
    // Enemy의 스폰 위치 결정
    SetSpawnWorldPosition();

}

Enemy::~Enemy()
{

}

// enemy가 월드 맵의 가장자리에서 어디에 spawn될지 랜덤으로 정하는 함수
void Enemy::SetSpawnWorldPosition()

{

    // 랜덤 설정 변수
    int random = Random(1, 10);
    int randomLeftRight = Random(1, 10);
    int randomUpDown = Random(1, 10);

    Vector2 tmpSpawnPosition;


    // 짝수일 경우, 좌우 선택
    if (random % 2 == 0)
    {
        //짝수인 경우 왼쪽에서 스폰
        if (randomLeftRight % 2 == 0)
        {

            spawnPosition = SpawnPosition::Left;

            //int tmp = mapSize.y;
            SetWorldPosition(0, Random(0, gameLevel->mapSize.y));
        }
        // 홀수인 경우 오른쪽에서 스폰
        else
        {

            spawnPosition = SpawnPosition::Right;

            SetWorldPosition(gameLevel->mapSize.x, Random(0, gameLevel->mapSize.y));
        }

    }
    // 홀수일 경우, 상하 선택
    else
    {
        // 짝수인 경우 위에서 스폰
        if (randomLeftRight % 2 == 0)
        {
            spawnPosition = SpawnPosition::Up;
            SetWorldPosition(Random(0, gameLevel->mapSize.x), 0);

        }
        // 홀수인 경우 아래에서 스폰
        else
        {
            spawnPosition = SpawnPosition::Down;
            SetWorldPosition(Random(0, gameLevel->mapSize.x), gameLevel->mapSize.y);
        }
    }
}

void Enemy::Update(float deltaTime)
{
    // Enemy의 현재 월드맵상의 위치
    Vector2 EnemyCurrentWorldPosition = GetWorldPosition();
    // Player의 현재 월드맵상의 위치를 알아오는 변수.
    Vector2 PlayerCurrentWorldPosition = Player::Get().GetPlayerWorldPosition();

    // Enemy가 플레이어 방향으로 이동
    Vector2 direnction = PlayerCurrentWorldPosition - EnemyCurrentWorldPosition;

    int Length = static_cast<int>(sqrt(direnction.x * direnction.x + direnction.y * direnction.y));

    if (Length > 0)
    {
        // ToDo: 일단 이상하게 돌아가면 살펴보기
        // 여기서 이렇게 해줘야 한다는데...    //EnemyCurrentWorldPosition += direnction * speed * deltaTime;
        EnemyCurrentWorldPosition = EnemyCurrentWorldPosition + direnction ;
        SetWorldPosition(EnemyCurrentWorldPosition);
    }


}
