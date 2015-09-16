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

#ifndef OZCOLLIDE_AABBTREEAABB_BUILDER_H
#define OZCOLLIDE_AABBTREEAABB_BUILDER_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/box.h>
#include <ozcollide/vector.h>

ENTER_NAMESPACE_OZCOLLIDE

class AABBTreeAABB;
class Monitor;

/**
 * A helper to create an AABBTreeAABB from a set of AABB.
 */
class AABBTreeAABB_Builder {
public:

    /**
     * Creates an instance to build an AABBTreeAABB.
     */
    OZCOLLIDE_API AABBTreeAABB_Builder();

    /**
     * Destructs that instance.
     */
    OZCOLLIDE_API ~AABBTreeAABB_Builder();

    /**
     * Constructs a AABBTreeAABB from a set of AABB.
     * @param nbBoxes Number of boxes.
     * @param boxes The set of boxes.
     * @param leafDepth Maximum number of boxes we can find on a leaf. Default value is 1 but usually a value of 4 is a good compromise (lesser leaves so smaller tree).
     * @param monitor If not NULL, it's used to monitor the progression of the build.
     * @return A ready to work AABBTreeAABB instance.
     */
    OZCOLLIDE_API AABBTreeAABB* buildFromList(  int nbBoxes,
                                                const Box *,
                                                int leafDepth = 1,
                                                Monitor *moni = NULL);

private:

    class WorkingItem {
    public:
        Box aabb;
        int left, right; // both to -1 whether it's a leaf
        Vector<Box> boxes;
    };

    void workOnItem(WorkingItem &, int leafDepth);
    int classifyAABB(const Box &, int axis, float middle);

    Vector<WorkingItem*>    items_;
    AABBTreeAABB            *tree_;
};

LEAVE_NAMESPACE

#endif
