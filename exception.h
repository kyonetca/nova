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

#define LEVEL_OK 0
#define LEVEL_NOTICE 1
#define LEVEL_INFORMATION 2
#define LEVEL_DEPRECATED 3
#define LEVEL_WARNING 4
#define LEVEL_ERROR 5
#define LEVEL_FATAL_ERROR 6

#define TYPE_NOT_IMPLEMENTED 1
#define TYPE_ALLOCATION_FAILED 2
#define TYPE_FREE_FAILED 3
#define FAILED_TO_CREATE_THREAD 4

typedef unsigned short ExceptionType;
typedef unsigned short ExceptionLevel;
typedef char * ExceptionMessage;
typedef char * ExceptionStacktrace;


int ThrowException(ExceptionType Type, ExceptionLevel Level, ExceptionMessage Message, ExceptionStacktrace Stacktrace);

int SetExceptionCallback(void (*CallbackFunction)(ExceptionType, ExceptionLevel, ExceptionMessage, ExceptionStacktrace));

void InternalExceptionHandler(ExceptionType Type, ExceptionLevel Level, ExceptionMessage Message, ExceptionStacktrace Stacktrace);