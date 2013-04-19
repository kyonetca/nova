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
#include <pthread.h>

#include "global_constants.h"
#include "exception.h"
#include "network.h"
#include "route.h"
#include "utility.h"

void Finished(NovaClient client) {
	Print("Hello World!");
}

void NetworkInitialize() {	
	ThrowException(TYPE_NOT_IMPLEMENTED, LEVEL_FATAL_ERROR, "Function NetworkInitialize is not implemented yet.", "NetworkInitialize");
	NovaGroup connect;
	
	connect = JoinGroup(connect, CONNECT_GROUP, false, false);


	FindGroupMemberAsync(connect, Finished);
	pthread_join(async, NULL);
	Print("Good Bye");
}

NovaGroup JoinGroup(NovaGroup Group, long GroupName, int Encrypted, int Private) {
	Group.ID = GroupName;
	Group.Encrypted = Encrypted;
	Group.Private = Private;
	return Group;
}

int LeaveGroup(NovaGroup GroupID) {
	return 0;
}
