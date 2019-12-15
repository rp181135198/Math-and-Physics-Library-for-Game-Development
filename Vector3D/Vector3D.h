//---------------------------------------------------------------------//
// Vector3D.h                                                          //
// Provide all 3D Vector related useful methods                        //
//                                                                     //
// By: Ramesh Prasad (Github: rp181135198)                             //
//---------------------------------------------------------------------//
#ifndef VECTOR3D_H
#define VECTOR3D_H
//-----------------------------------------------------------------------
#include <math.h>
//-----------------------------------------------------------------------
class Vector3D
{
    public:
        Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

        //Get Vectors
        float getX() { return m_x; }
        float getY() { return m_y; }
        float getZ() { return m_z; }

        //Set Vectors
        void setX(float x) { m_x=x; }
        void setY(float y) { m_y=y; }
        void setZ(float z) { m_z=z; }

        //Get Length of Vectors
        float length() { return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }

        //Get Dot Product of Two Vectors
        float dot(Vector3D &v2) { return (m_x * v2.getX() + m_y * v2.getY() + m_z * v2.getZ()); }

        //Get Cross Product of Two Vectors
        Vector3D cross(Vector3D &v2) { return Vector3D(m_y*v2.getZ() - m_z*v2.getY(), m_z*v2.getX() - m_x*v2.getZ(), m_x*v2.getY() - m_y*v2.getX()); }

        //Addition of two Vectors
        Vector3D operator+(const Vector3D& v2) const
        {
            return Vector3D(m_x + v2.m_x, m_y + v2.m_y, m_z + v2.m_z);
        }

        friend Vector3D& operator+=(Vector3D& v1, const Vector3D& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;
            v1.m_z += v2.m_z;

            return v1;
        }

        //Multiplication by a Scalar Number
        Vector3D operator*(float scalar)
        {
            return Vector3D(m_x * scalar, m_y * scalar, m_z * scalar);
        }

        Vector3D& operator*=(float scalar)
        {
            m_x *= scalar;
            m_y *= scalar;
            m_z *= scalar;

            return *this;
        }

        //Subtraction of two Vectors
        Vector3D operator-(const Vector3D& v2) const
        {
            return Vector3D(m_x - v2.m_x, m_y - v2.m_y, m_z - v2.m_z);
        }

        friend Vector3D& operator-=(Vector3D& v1, const Vector3D& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;
            v1.m_z -= v2.m_z;

            return v1;
        }

        //Divide by a Scalar Number
        Vector3D operator/(float scalar)
        {
            return Vector3D(m_x/scalar , m_y/scalar, m_z/scalar);
        }

        Vector3D& operator/=(float scalar)
        {
            m_x /= scalar;
            m_y /= scalar;
            m_z /= scalar;

            return *this;
        }

        //Normalizing a Vector
        void normalize()
        {
            float l=length();
            if(l>0) // we never to attempt to divide by 0
            {
                (*this) *= 1/l;
            }
        }
        virtual ~Vector3D() {}

    protected:

    private:
        float m_x;
        float m_y;
        float m_z;
};
//-----------------------------------------------------------------------
#endif // VECTOR3D_H
