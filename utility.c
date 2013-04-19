/* 
	
	Nova - Decentralized Computing Network
	Copyright (C) 2012 - 2013  Jan Peter Koenig

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global_constants.h"
#include "exception.h"

int TotalAllocatedMemory = 0;

// Prints out a Program info / License Info Message
void PrintWelcomeMessage() {
	fprintf(stdout, "%s\n%s\n", 
		"Nova - Copyright (C) 2013 Jan Peter Koenig",
		"This program comes with ABSOLUTELY NO WARRANTY");
	
}

void *GetVoidMemory(size_t Size) {
	void * Data = malloc(Size);
	if (Data == NULL) {
		ThrowException(TYPE_ALLOCATION_FAILED, LEVEL_ERROR, "Failed to allocate Memory.", "GetVoidMemory");
	}
	TotalAllocatedMemory += Size;
	return Data;
}

char *GetCharMemory(size_t Size) {
	return (char *)GetVoidMemory(Size);
}

void *GetIntMemory(size_t Size) {
	return (int *)GetVoidMemory(Size);
}

int GetTotalAllocatedSpace() {
	return TotalAllocatedMemory;
}

void FreeMemory(void *Data) {
	if (Data == NULL) {
		ThrowException(TYPE_FREE_FAILED, LEVEL_ERROR, "Failed to free Null Pointer", "FreeMemory");
		return;
	}
	TotalAllocatedMemory -= sizeof(Data);
	free(Data);
}