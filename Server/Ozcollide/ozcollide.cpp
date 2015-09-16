/*
OZCollide - Collision Detection Library
Copyright (C) 2014 Igor Kravtchenko

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Contact the author: igor@tsarevitch.org
*/

#include <ozcollide/ozcollide.h>

ENTER_NAMESPACE_OZCOLLIDE

const char* getErrorString(ERR _err)
{
	switch(_err) {
	case NOERR:
		return "No error";

	case ERR_CANNOT_OPEN:
		return "Cannot open file";

	case ERR_INVALID_FORMAT:
		return "Invalid file format";

	default:
		return "Non-recensed error";
	}
}

int getLibVersion()
{
	return OZCOLLISON_VERSION;
}

LEAVE_NAMESPACE
