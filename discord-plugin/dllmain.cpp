#include "dllmain.h"
#include <string> 
#include <stdlib.h>

void MainThread()
{
	while (*(DWORD*)0xC8D4C0 != 9)
		Sleep(350);

	pGame = new Game();

	HMODULE module = NULL;

	if (GetModuleHandleA("samp.dll")) // let's test if this code works to not supposed to be used with SA-MP.
	{
		FreeLibraryAndExitThread(module, 0);
	}
	else
	{
		Discord_Initialize(APPLICATION_ID, 0, 0, 0);

		std::string details, state, smallImageText, largeImageText;

		DiscordRichPresence drp;

		drp = { 0 };
		drp.startTimestamp = time(0);

	while (1)
	{

		if (*reinterpret_cast<int*>(0xB6F5F0))
		{

			details = "Money: $" + std::to_string(pGame->GetPlayerMoney());
			state = "Time: " + pGame->GetTime();
			smallImageText = weaponNames[pGame->GetCurrentWeapon()];
			largeImageText = "Modified GTA SA Discord RPC";

			drp.largeImageKey = "game_icon";
			drp.largeImageText = largeImageText.c_str();
			drp.smallImageText = smallImageText.c_str();
			drp.smallImageKey = weaponIcons[pGame->GetCurrentWeapon()].c_str();;
			drp.details = details.c_str();
			drp.state = state.c_str();

			Discord_UpdatePresence(&drp);
			Sleep(15000);
		    }
		}
	}
}

std::string cp1251_to_utf8(const char* str)
{
	std::string res;
	int result_u, result_c;
	result_u = MultiByteToWideChar(1251, 0, str, -1, 0, 0);
	if (!result_u) { return 0; }
	wchar_t* ures = new wchar_t[result_u];
	if (!MultiByteToWideChar(1251, 0, str, -1, ures, result_u)) {
		delete[] ures;
		return 0;
	}
	result_c = WideCharToMultiByte(65001, 0, ures, -1, 0, 0, 0, 0);
	if (!result_c) {
		delete[] ures;
		return 0;
	}
	char* cres = new char[result_c];
	if (!WideCharToMultiByte(65001, 0, ures, -1, cres, result_c, 0, 0)) {
		delete[] cres;
		return 0;
	}
	delete[] ures;
	res.append(cres);
	delete[] cres;
	return res;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), 0, 0, 0);
	}
	else if (reason == DLL_PROCESS_DETACH)
        Discord_Shutdown();

	return TRUE;
}