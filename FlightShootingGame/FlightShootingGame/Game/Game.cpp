#pragma once

#include "Game.h"

// 레벨
#include "Level/Level.h"

#include "Level/Menu/MainMenuLevel.h"
#include "Level/Menu/PauseMenuLevel.h"
#include "Level/Menu/WeaponSetupMenuLevel.h"

#include "Level/Game/GameLevel.h"

// 싱글톤 정적 변수 초기화
Game* Game::instance = nullptr;

Game::Game()
	:	mainMenuLevel(new MainMenuLevel()),
		weaponSetupMenuLevel(new WeaponSetupMenuLevel()),
		gameLevel(new GameLevel()),
		pauseMenuLevel(new PauseMenuLevel())
{

	instance = this;

	// 커서 안 보이게 설정
	SetCursorType(CursorType::NoCursor);

	// 메인 메뉴를 로드 : 처음엔 무조건 메인 레벨에서 시작.
	LoadLevel(mainMenuLevel);
}


Game::~Game()
{

	delete mainMenuLevel;
	delete weaponSetupMenuLevel;
	delete gameLevel;
	delete pauseMenuLevel;

	LoadLevel(nullptr);
	
}
void Game::ChangeLevel(Level* level)
{
	LoadLevel(level);
}

void Game::RestartGame(Level* currentLevel)
{
	delete gameLevel;
	gameLevel = new GameLevel();
	LoadLevel(gameLevel);
}

Level* Game::GetMainMenuLevel() const
{
	return mainMenuLevel;
}

Level* Game::GetWeaponSetupMenuLevel() const
{
	return weaponSetupMenuLevel;
}

Level* Game::GetPauseMenuLevel() const
{
	return pauseMenuLevel;
}

Level* Game::GetGameLevel() const
{
	return gameLevel;
}

