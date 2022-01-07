#include "game.h"

Game* pGame;

std::string Game::GetTime() {
	BYTE minutes = *reinterpret_cast<BYTE*>(0xB70152);
	std::string minstr;
	if (minutes < 10) minstr = "0" + std::to_string(minutes);
	else minstr = std::to_string(minutes);
	return std::to_string(*reinterpret_cast<BYTE*>(0xB70153)) + ":" + minstr;
}

int Game::GetPlayerMoney() {
	return *reinterpret_cast<int*>(0xB7CE50);
}

int Game::GetCurrentWeapon()
{
	return *reinterpret_cast<int*>(0xBAA410);
}