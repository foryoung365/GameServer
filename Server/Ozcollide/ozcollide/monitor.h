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

#ifndef OZCOLLIDE_MONITOR_H
#define OZCOLLIDE_MONITOR_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

/**
 * @brief A Monitor is an abstract user callback method to get informations about an event in progress.
 */
class Monitor {
public:
    /**
     * @brief Called when a text information can be useful for the user.
     * @param mess The text (string zero) to be displayed. The method can do nothing.
     */
    virtual void write(const char *mess) = 0;

    /**
     * @brief Informs about the current progression of the event. The method can do nothing or shows a progress bar or whatever you want.
     * @param pos The position from 0 to len.
     * @param len The length of the event.
     */
    virtual void setProgress(int pos, int len) = 0;
};

LEAVE_NAMESPACE

#endif
