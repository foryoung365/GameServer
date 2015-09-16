/*
OZCollide - Collision Detection Library
Copyright (C) 2006-2014 by Igor Kravtchenko

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

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#ifndef OZCOLLIDE_DIST_POINTLINE_H
#define OZCOLLIDE_DIST_POINTLINE_H

ENTER_NAMESPACE_OZCOLLIDE

class Vec3f;

OZCOLLIDE_API float sqrDistancePointToLine( const Vec3f &point,
                                            const Vec3f &pt0,
                                            const Vec3f &pt1,
                                            Vec3f *linePt = NULL);

OZCOLLIDE_API float distancePointToLine(const Vec3f &point,
                                        const Vec3f &pt0,
                                        const Vec3f &pt1,
                                        Vec3f *linePt = NULL);

LEAVE_NAMESPACE

#endif
