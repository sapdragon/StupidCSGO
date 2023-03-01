#pragma once
/* Bootloader - Bootloader is the main class for initializing the cheat, it is called directly from the DllMain. */

/* Includes */
#include "../Core.hpp"

class CBootLoader
{
public:
	CBootLoader();

private:
	/* Allocate console for cheat */
	void CreateConsole( );
};