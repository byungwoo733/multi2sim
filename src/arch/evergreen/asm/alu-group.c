/*
 *  Multi2Sim
 *  Copyright (C) 2013  Rafael Ubal (ubal@ece.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <lib/class/class.h>
#include <lib/mhandle/mhandle.h>

#include "alu-group.h"


/*
 * Class 'EvgALUGroup'
 */

void EvgALUGroupCreate(EvgALUGroup *self, EvgAsm *as)
{
	int i;

	/* Initialize */
	self->as = as;

	/* Create instructions */
	for (i = 0; i < EVG_ALU_GROUP_SIZE; i++)
		new_static(&self->inst[i], EvgInst, as);
}


void EvgALUGroupDestroy(EvgALUGroup *self)
{
	int i;

	/* Destroy instructions */
	for (i = 0; i < EVG_ALU_GROUP_SIZE; i++)
		delete_static(&self->inst[i]);
}
