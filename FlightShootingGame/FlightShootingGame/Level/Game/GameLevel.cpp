#include "GameLevel.h"
#include "Game/Game.h"
#include "Engine/Engine.h"
#include "Actor/Actor.h"

#include "Actor/Player/Player.h"
static const char* enemyType[]
{

	"A",
	"B",
	"C"
};
GameLevel::GameLevel()
	:	screenSize(Engine::Get().ScreenSize().x, Engine::Get().ScreenSize().y),
		mapSize(360,90)
{
	player = new Player("<A>");
	AddActor(player);
}

GameLevel::~GameLevel()
{
}

void GameLevel::Draw()
{

	Super::Draw();


	

}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
	//timer.Update(deltaTime);
	//예외 처리
	if (deltaTime > 1.0f)
	{
		return;
	}

	if (Game::Get().GetKeyDown(VK_ESCAPE))
	{

		Game::Get().ChangeLevel(Game::Get().GetPauseMenuLevel());
	}
	Vector2 currentPlayerWorldPosition = player->GetWorldPosition();

	Vector2 ForPrintScreenIndex(currentPlayerWorldPosition.x - static_cast<int>(screenSize.x / 2), currentPlayerWorldPosition.y - static_cast<int>(screenSize.y / 2));
}