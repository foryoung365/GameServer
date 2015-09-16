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

#ifndef OZCOLLIDE_MATRIX_H
#define OZCOLLIDE_MATRIX_H

#ifndef OZCOLLIDE_PCH
#include <ozcollide/ozcollide.h>
#endif

#include <ozcollide/vec3f.h>
	
ENTER_NAMESPACE_OZCOLLIDE

/**
 * Defines a 3x3 Matrix which is a matrix optimised only for rotation.
 */
class Matrix3x3 {
public:

    /**
     * Sets the matrix to the identity.
     * That means, a rotation matrix that does nothing.
     */
    ozinline void identity()
    {
        m_[0][0] = 1;   m_[0][1] = 0;   m_[0][2] = 0;
        m_[1][0] = 0;   m_[1][1] = 1;   m_[1][2] = 0;
        m_[2][0] = 0;   m_[2][1] = 0;   m_[2][2] = 1;
    }

    /**
     * Multiply a point by this matrix.
     * @param _pt The point to be rotated by the matrix.
     * @return The rotated point.
     */
    ozinline Vec3f mul(const Vec3f &_pt) const
    {
        Vec3f p;
        p.x = _pt.x * m_[0][0] + _pt.y * m_[0][1] + _pt.z * m_[0][2];
        p.y = _pt.x * m_[1][0] + _pt.y * m_[1][1] + _pt.z * m_[1][2];
        p.z = _pt.x * m_[2][0] + _pt.y * m_[2][1] + _pt.z * m_[2][2];
        return p;
    }

    /** The array that defines the rotation matrix. */
    float m_[3][3];
};

/**
 * Defines a "normal" 4x4 matrix that does rotation and translation.
 */
class Matrix {
public:

    /**
     * Sets the matrix to the identity.
     * That means, a matrix that does nothing (no rotation nor translation).
     */
    ozinline void identity()
    {
        m_[0][0] = 1; m_[0][1] = 0; m_[0][2] = 0; m_[0][3] = 0;
        m_[1][0] = 0; m_[1][1] = 1; m_[1][2] = 0; m_[1][3] = 0;
        m_[2][0] = 0; m_[2][1] = 0; m_[2][2] = 1; m_[2][3] = 0;
        m_[3][0] = 0; m_[3][1] = 0; m_[3][2] = 0; m_[3][3] = 1;
    }

    /**
     * Recopy the 3x3 rotation matrix from a Matrix3x3.
     * Only the rotation part of this 4x4 matrix is affected.
     * @param _mat The matrix to recopy from.
     */
    ozinline void recopyFrom3x3(const Matrix3x3 &_mat)
    {
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < 3; i++)
                m_[i][j] = _mat.m_[i][j];

        m_[3][0] = 0;
        m_[3][1] = 0;
        m_[3][2] = 0;

        m_[0][3] = 0;
        m_[1][3] = 0;
        m_[2][3] = 0;
        m_[3][3] = 1;
    }

    /**
     * Transpose the matrix. i.e.: inverse columns and lines
     * @param _mat The transposed matrix.
     */
    ozinline void transpose(Matrix &_mat)
    {
        for (int j = 0; j < 4; j++)
            for (int i = 0; i < 4; i++)
                _mat.m_[i][j] = m_[j][i];
    }

    /**
     * Multiply a point by this matrix.
     * @param _pt The point to be rotated by the matrix.
     * @return The rotated point.
     */
    ozinline Vec3f mul(const Vec3f &_pt) const
    {
        Vec3f p;
        p.x = _pt.x * m_[0][0] + _pt.y * m_[0][1] + _pt.z * m_[0][2] + m_[0][3];
        p.y = _pt.x * m_[1][0] + _pt.y * m_[1][1] + _pt.z * m_[1][2] + m_[1][3];
        p.z = _pt.x * m_[2][0] + _pt.y * m_[2][1] + _pt.z * m_[2][2] + m_[2][3];
        return p;
    }

    float m_[4][4];
};

LEAVE_NAMESPACE

#endif
