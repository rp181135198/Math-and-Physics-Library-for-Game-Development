#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>

class Vector2D
{
    public:
        Vector2D(float x, float y) : m_x(x), m_y(y) {}

        //Get Vectors
        float getX() { return m_x; }
        float getY() { return m_y; }

        //Set Vectors
        void setX(float x) { m_x=x; }
        void setY(float y) { m_y=y; }

        //Get Length of Vectors
        float length() { return sqrt(m_x * m_x + m_y * m_y); }

        //Get Dot Product of Two Vectors
        float dot(Vector2D &v2) { return (m_x * v2.getX() + m_y * v2.getY()); }

        //Addition of two Vectors
        Vector2D operator+(const Vector2D& v2) const
        {
            return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
        }

        friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;

            return v1;
        }

        //Multiplication by a Scalar Number
        Vector2D operator*(float scalar)
        {
            return Vector2D(m_x * scalar, m_y * scalar);
        }

        Vector2D& operator*=(float scalar)
        {
            m_x *= scalar;
            m_y *= scalar;

            return *this;
        }

        //Subtraction of two Vectors
        Vector2D operator-(const Vector2D& v2) const
        {
            return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
        }

        friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;

            return v1;
        }

        //Divide by a Scalar Number
        Vector2D operator/(float scalar)
        {
            return Vector2D(m_x/scalar , m_y/scalar);
        }

        Vector2D& operator/=(float scalar)
        {
            m_x /= scalar;
            m_y /= scalar;

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
        virtual ~Vector2D() {}

    protected:

    private:
        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
