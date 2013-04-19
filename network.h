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

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 3726

typedef struct {
	long ID;
	short Encrypted, Private;
} NovaGroup;

typedef struct {
	NovaGroup *GroupID;
	struct sockaddr_in IPAddress;
	
	struct NovaClient *Next;
	struct NovaClient *Previous;
} NovaClient;

void NetworkInitialize();

void JoinGroup(NovaGroup Group, long GroupName, int Encypted, int Private);

int LeaveGroup(NovaGroup GroupID);

void GroupIncommingMessage(NovaGroup Group);