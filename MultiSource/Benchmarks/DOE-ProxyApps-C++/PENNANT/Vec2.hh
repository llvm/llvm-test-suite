/*
 * Vec2.hh
 *
 *  Created on: Dec 21, 2011
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef VEC2_HH_
#define VEC2_HH_

#include <cmath>


// This struct is defined with all functions inline,
// to give the compiler maximum opportunity to optimize.

struct double2
{
    typedef double value_type;
    double x, y;
    inline double2() : x(0.), y(0.) {}
    inline double2(const double& x_, const double& y_) : x(x_), y(y_) {}
    inline double2(const double2& v2) : x(v2.x), y(v2.y) {}
    inline ~double2() {}

    inline double2& operator=(const double2& v2)
    {
        x = v2.x;
        y = v2.y;
        return(*this);
    }

    inline double2& operator+=(const double2& v2)
    {
        x += v2.x;
        y += v2.y;
        return(*this);
    }

    inline double2& operator-=(const double2& v2)
    {
        x -= v2.x;
        y -= v2.y;
        return(*this);
    }

    inline double2& operator*=(const double& r)
    {
        x *= r;
        y *= r;
        return(*this);
    }

    inline double2& operator/=(const double& r)
    {
        x /= r;
        y /= r;
        return(*this);
    }

}; // double2

inline double2 make_double2(const double& x_, const double& y_) {
    return(double2(x_, y_));
}



// comparison operators:

// equals
inline bool operator==(const double2& v1, const double2& v2)
{
    return((v1.x == v2.x) && (v1.y == v2.y));
}

// not-equals
inline bool operator!=(const double2& v1, const double2& v2)
{
    return(!(v1 == v2));
}


// unary operators:

// unary plus
inline double2 operator+(const double2& v)
{
    return(v);
}

// unary minus
inline double2 operator-(const double2& v)
{
    return(double2(-v.x, -v.y));
}


// binary operators:

// add
inline double2 operator+(const double2& v1, const double2& v2)
{
    return(double2(v1.x + v2.x, v1.y + v2.y));
}

// subtract
inline double2 operator-(const double2& v1, const double2& v2)
{
    return(double2(v1.x - v2.x, v1.y - v2.y));
}

// multiply vector by scalar
inline double2 operator*(const double2& v, const double& r)
{
    return(double2(v.x * r, v.y * r));
}

// multiply scalar by vector
inline double2 operator*(const double& r, const double2& v)
{
    return(double2(v.x * r, v.y * r));
}

// divide vector by scalar
inline double2 operator/(const double2& v, const double& r)
{
    double rinv = (double) 1. / r;
    return(double2(v.x * rinv, v.y * rinv));
}


// other vector operations:

// dot product
inline double dot(const double2& v1, const double2& v2)
{
    return(v1.x * v2.x + v1.y * v2.y);
}

// cross product (2D)
inline double cross(const double2& v1, const double2& v2)
{
    return(v1.x * v2.y - v1.y * v2.x);
}

// length
inline double length(const double2& v)
{
    return(std::sqrt(v.x * v.x + v.y * v.y));
}

// length squared
inline double length2(const double2& v)
{
    return(v.x * v.x + v.y * v.y);
}

// rotate 90 degrees counterclockwise
inline double2 rotateCCW(const double2& v)
{
    return(double2(-v.y, v.x));
}

// rotate 90 degrees clockwise
inline double2 rotateCW(const double2& v)
{
    return(double2(v.y, -v.x));
}

// project v onto subspace perpendicular to u
// u must be a unit vector
inline double2 project(double2& v, const double2& u)
{
    // assert(length2(u) == 1.);
    return v - dot(v, u) * u;
}


#endif /* VEC2_HH_ */
