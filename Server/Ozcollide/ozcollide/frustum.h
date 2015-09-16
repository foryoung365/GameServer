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

#ifndef OZCOLLIDE_FRUSTUM_H
#define OZCOLLIDE_FRUSTUM_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/plane.h>

ENTER_NAMESPACE_OZCOLLIDE

/**
 * Generic class to define a frustum.
 * A frustum is made of 6 planes. These 6 planes correspond to a camera view with the top, the bottom, the left, the right, the near and the far.
 */
class Frustum {
public:

    /**
     * Constructs a zero filled frustum.
     */
    Frustum()
    {
        for (int i = 0; i < 6; i++) {
            planes[i].a = 0;
            planes[i].b = 0;
            planes[i].c = 0;
            planes[i].d = 0;
        }
    }

    Plane planes[6]; /**< The planes used to made the frustum.*/
};

LEAVE_NAMESPACE

#endif
