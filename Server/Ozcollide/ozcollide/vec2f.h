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

#ifndef OZCOLLIDE_VEC2F_H
#define OZCOLLIDE_VEC2F_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

ENTER_NAMESPACE_OZCOLLIDE

/**
 * A typical 2D vector class.
 */
class Vec2f {
public:

    ozinline Vec2f()
    {
    }

    ozinline Vec2f(float _x, float _y) : x(_x), y(_y)
    {
    }

    ozinline Vec2f operator - () const
    {
        return Vec2f(-x, -y);
    }

    ozinline void operator -= (const Vec2f &_v)
    {
        x -= _v.x;
        y -= _v.y;
    }

    ozinline void operator += (const Vec2f &_v)
    {
        x += _v.x;
        y += _v.y;
    }

    ozinline void operator *= (float _mul)
    {
        x *= _mul;
        y *= _mul;
    }

    ozinline void operator *= (const Vec2f &_v)
    {
        x *= _v.x;
        y *= _v.y;
    }

    ozinline void operator /= (float _div)
    {
        float mul = 1.0f / _div;
        x *= mul;
        y *= mul;
    }

     ozinline Vec2f operator - (const Vec2f &_v) const
     {
         return Vec2f(x - _v.x, y - _v.y);
     }

     ozinline Vec2f operator + (const Vec2f &_v) const
     {
         return Vec2f(x + _v.x, y + _v.y);
     }

     ozinline Vec2f operator * (const Vec2f &_v) const
     {
         return Vec2f(x * _v.x, y * _v.y);
     }
	
     ozinline Vec2f operator * (float _m) const
     {
         return Vec2f(x * _m, y * _m);
     }

     ozinline Vec2f operator / (const Vec2f &_v) const
     {
         return Vec2f(x / _v.x, y / _v.y);
     }

     ozinline Vec2f operator / (float _d) const
     {
         float m = 1.0f / _d;
         return Vec2f(x * m, y * m);
     }

     ozinline Vec2f operator | (const Vec2f &_d) const
     {
         return Vec2f(y * _d.y - x * _d.y, // FIXME!
                 y * _d.x - x * _d.y);
     }

     ozinline bool operator == (const Vec2f &_v) const
     {
         if (x == _v.x && y == _v.y)
             return true;
         return false;
     }

     ozinline bool operator != (const Vec2f &_v) const
     {
         if (x != _v.x || y != _v.y)
             return true;
         return false;
     }

     ozinline float operator [] (int _i) const
     {
         const float *val = &x;
         return val[_i];
     }

     ozinline float len() const
     {
         float len = x * x + y * y;
         return (float) sqrt(len);
     }

     ozinline float lenSq() const
     {
         return x * x + y * y;
     }

     ozinline float dot(const Vec2f &_v) const
     {
         return x * _v.x + y * _v.y;
     }

     ozinline void normalize()
     {
         float ln = len();
         if (!ln)
             return;
         
         float div = 1.0f / ln;
         x *= div;
         y *= div;
     }

    ozinline void positive()
    {
        if (x < 0) x = -x;
        if (y < 0) y = -y;
    }

    float x;
    float y;
};

ozinline Vec2f operator * (float _m, const Vec2f &_v)
{
    return Vec2f(_v.x * _m, _v.y * _m);
}

LEAVE_NAMESPACE

#endif
