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

// Boolean Datatype
#define bool short;
#define true 1
#define false 0

// Debug Level
#define DEBUG_DEFAULT 0x1
#define DD DEBUG_DEFAULT

#define DEBUG_VERBOSE 0x2
#define DV DEBUG_VERBOSE

#define DEBUG_LOGGING 0x4
#define DL DEBUG_LOGGING

#define DEBUG_INTERNAL 0x8
#define DI DEBUG_INTERNAL

#define DEBUG_ALL 0xF
#define DA DEBUG_ALL

#define DEBUG_PRI 0xF
#define DEBUG_INT 0xC
#define DEBUG_VER 0xE

// Prints out a Program info / License Info Message
void PrintWelcomeMessage();

void *GetVoidMemory(size_t Size);

char *GetCharMemory(size_t Size);

int *GetIntMemory(size_t Size);

int GetTotalAllocatedSpace();

void FreeMemory(void *Data);

void Print(char *Message);

void PrintE(char *Message);

void SetDebugLevel(int DebugLevel);
