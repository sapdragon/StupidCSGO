//===== Copyright � 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: Shared code for parsing / searching for characters in a string
//			using lookup tables
//
// $Workfile:     $
// $Date:         $
// $NoKeywords: $
//===========================================================================//

#pragma once
#include <string.h>

struct characterset_t
{
    char m_aSet[256];
};


// This is essentially a strpbrk() using a precalculated lookup table
//-----------------------------------------------------------------------------
// Purpose: builds a simple lookup table of a group of important characters
// Input  : *pSetBuffer - pointer to the buffer for the group
//			*pSetString - list of characters to flag
//-----------------------------------------------------------------------------
inline void CharacterSetBuild(characterset_t* pSetBuffer, const char* szSetString)
{
    int i = 0;

    // Test our pointers
    if (!pSetBuffer || !szSetString)
        return;

    memset(pSetBuffer->m_aSet, 0, sizeof(pSetBuffer->m_aSet));

    while (szSetString[i]) {
        pSetBuffer->m_aSet[szSetString[i]] = 1;
        i++;
    }
}


//-----------------------------------------------------------------------------
// Purpose: 
// Input  : *pSetBuffer - pre-build group buffer
//			character - character to lookup
// Output : int - 1 if the character was in the Set
//-----------------------------------------------------------------------------
#define IN_CHARACTERSET( SetBuffer, character )		((SetBuffer).m_aSet[(character)])