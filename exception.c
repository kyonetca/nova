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
#include "utility.h"

void (*CallbackFunction)(ExceptionType, ExceptionLevel, ExceptionMessage, ExceptionStacktrace) = null;

int ThrowException(ExceptionType Type, ExceptionLevel Level, ExceptionMessage Message, ExceptionStacktrace Stacktrace) {
	
	if (CallbackFunction == null)
		CallbackFunction = InternalExceptionHandler;
	

	CallbackFunction(Type, Level, Message, Stacktrace);

	return EXIT_SUCCESS;
}

void InternalExceptionHandler(ExceptionType Type, ExceptionLevel Level, ExceptionMessage Message, ExceptionStacktrace Stacktrace) {	
	char errmsg[1024];
	char level[256];

	memset(&errmsg, 0, 1024);
	memset(&level, 0, 256);

	switch (Level) {
	case LEVEL_OK:
		sprintf(level, "%s", "OK");
		break;
	case LEVEL_NOTICE:
		sprintf(level, "%s", "Notice");
		break;
	case LEVEL_INFORMATION:
		sprintf(level, "%s", "Information");
		break;
	case LEVEL_DEPRECATED:
		sprintf(level, "%s", "Deprecated");
		break;
	case LEVEL_WARNING:
		sprintf(level, "%s", "Warning");
		break;
	case LEVEL_ERROR:
		sprintf(level, "%s", "Error");
		break;
	case LEVEL_FATAL_ERROR:
		sprintf(level, "%s", "Fatal Error");
		break;

	}

	switch (Type) {
	case TYPE_NOT_IMPLEMENTED:
		sprintf(errmsg, "%s%s%s%s%s%s%s", "-------------------------------------------------------\nAn exception was thrown by ",
			Stacktrace, ":\n" , level , ", Not Implemented Exception:\n", Message, "\n-------------------------------------------------------\n"); 
		break;
	case TYPE_ALLOCATION_FAILED:
		sprintf(errmsg, "%s%s%s%s%s%s%s", "-------------------------------------------------------\nAn exception was thrown by ",
			Stacktrace, ":\n" , level , ", Memory Allocation Failed Exception:\n", Message, "\n-------------------------------------------------------\n"); 
		break;
	case TYPE_FREE_FAILED:
		sprintf(errmsg, "%s%s%s%s%s%s%s", "-------------------------------------------------------\nAn exception was thrown by ",
			Stacktrace, ":\n" , level , ", Memory Free Failed Exception:\n", Message, "\n-------------------------------------------------------\n"); 
		break;
	}

	PrintE(errmsg);
}

int SetExceptionCallback(void (*Func)(ExceptionType, ExceptionLevel, ExceptionMessage, ExceptionStacktrace)) {
	CallbackFunction = Func;
	
	return EXIT_SUCCESS;
}

