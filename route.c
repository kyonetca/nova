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
#include "route.h"
#include "network.h"

NovaGroup G_GroupID;
void (*G_Callback)(NovaClient);

NovaClient FindGroupMember(NovaGroup GroupID) {
	NovaClient cl;
	return cl;
}

// int pthread_create( pthread_t *thread, const pthread_attr_t *attribute, void *(*funktion)(void *), void *argumente );

void *FindGroupMemberSync(void * par) {
	void (*tmp)(NovaClient) = G_Callback;
	tmp(FindGroupMember(G_GroupID));

	return null;
}

void FindGroupMemberAsync(NovaGroup GroupID, void (*AsyncCallback)(NovaClient)) {
	G_GroupID = GroupID;
	G_Callback = AsyncCallback;

	if (pthread_create(&async, null, &FindGroupMemberSync, null) == -1) {
		ThrowException(FAILED_TO_CREATE_THREAD, LEVEL_ERROR, "Failed to create Thread", "FindGroupMemberAsync");
		return;
	}

	
}

