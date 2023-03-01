	
#include <thread>
#include "Bootloader/Bootloader.hpp"

/* Thread for call Bootstart */
void InitializationThread()
{
	/* Create instance of boot loader */
	CBootLoader BootLoader;
	
}


bool __stdcall DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason != DLL_PROCESS_ATTACH)
		return false;
	
	/* Create thread for call Bootstart */
	std::thread(InitializationThread).detach();

	return true;
}