#pragma once
#include <string>
#include <map>
#include <windows.h>

class Game
{
public:

	std::string GetTime();
	int GetCurrentWeapon();

};

const std::string weaponNames[] =
{
	{ "Fist" },
	{ "Brass Knuckles" },
	{ "Golf Club" },
	{ "Night Stick" },
	{ "Knife" },
	{ "Bat" },
	{ "Shovel" },
	{ "Pool Cue" },
	{ "Katana" },
	{ "Chainsaw" },
	{ "Purple Dildo" },
	{ "Dildo" },
	{ "Vibrator" },
	{ "Silver Vibrator" },
	{ "Flowers" },
	{ "Cane" },
	{ "Grenade" },
	{ "Teargas" },
	{ "Molotov" },
	{ " " }, // Unused
	{ " " }, // Unused
	{ " " }, // Unused
	{ "Colt 45" },
	{ "Silenced Pistol" },
	{ "Desert Eagle" },
	{ "Shotgun" },
	{ "Sawnoff-Shotgun" },
	{ "Combat Shotgun" },
	{ "Uzi" },
	{ "MP5" },
	{ "AK-47" },
	{ "M4" },
	{ "Tec-9" },
	{ "Country Rifle" },
	{ "Sniper Rifle" },
	{ "Rocket Launcher" },
	{ "Heat-Seeking RPG" },
	{ "Flamethrower" },
	{ "Minigun" },
	{ "Satchel Charges" },
	{ "Detonator" },
	{ "Spray Can" },
	{ "Fire Extinguisher" },
	{ "Camera" },
	{ "Night Vision" },
	{ "Thermal Goggles" },
	{ "Parachute" },
	{ "Fake Pistol" }
};

extern Game* pGame;
extern HMODULE module;
extern std::map <std::string, std::string> missionNames;