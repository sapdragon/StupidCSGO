#include "Bootloader.hpp"


/* Constructor of boot loader*/
CBootLoader::CBootLoader()
{
	/* Allocate console for dev. messages */
	CreateConsole();
}

void CBootLoader::CreateConsole()
{
	/* Allocate console, and handle return */
	if (!AllocConsole())
		return;

	/* Change standart input / output streams */
	freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	
	/* Set console title */
	if (!SetConsoleTitleA("StupidCSGO"))
		return;

	printf("StupidCSGO - Bootloader");
}
