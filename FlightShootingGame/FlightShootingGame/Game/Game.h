#pragma once

#include <Engine/Engine.h>

class Level;
class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// �̱��� ��ü ���� �Լ�.
	static Game& Get() { return *instance; }


	// ������ ��ȯ�ϰ� �����ϴ� �Լ�.
	void ChangeLevel(Level * level);

	// ������ mainGameLevel�� ����� �ٽ� �� ������ ����� �Լ�.
	void RestartGame(Level* currentLevel);

	// �޴� ���� Getter.
	Level* GetMainMenuLevel()			const;
	Level* GetWeaponSetupMenuLevel()	const;
	Level* GetPauseMenuLevel()			const;

	// ���� ���� Getter.
	Level* GetGameLevel()			const;


private:

	// �̱��� ������ ���� ���� ���� ����..
	static Game* instance; 


	// �޴� ����
	Level* mainMenuLevel;			// ���� �޴� ����.
	Level* weaponSetupMenuLevel;	// ���� ���� �޴� ����.
	Level* pauseMenuLevel;			// ���� �Ͻ� ���� �޴�.

	// ���� ����
	Level* gameLevel;			// ���� ���� ����.
};