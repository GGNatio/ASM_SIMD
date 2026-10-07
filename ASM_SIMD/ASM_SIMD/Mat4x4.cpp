#include "Mat4x4.h"

#include <cmath>

// Constructeur
Mat4x4::Mat4x4()
    : m{}
{
}

// Matrice identité
Mat4x4 Mat4x4::Identity()
{
    Mat4x4 result;

    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;

    return result;
}

// Matrice de translation
Mat4x4 Mat4x4::Translation(float x, float y, float z)
{
    Mat4x4 result = Identity();

    result.m[0][3] = x;
    result.m[1][3] = y;
    result.m[2][3] = z;

    return result;
}

// Rotation autour de X
Mat4x4 Mat4x4::RotationX(float angle)
{
    Mat4x4 result = Identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[1][1] = c;
    result.m[1][2] = -s;
    result.m[2][1] = s;
    result.m[2][2] = c;

    return result;
}

// Rotation autour de Y
Mat4x4 Mat4x4::RotationY(float angle)
{
    Mat4x4 result = Identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[0][0] = c;
    result.m[0][2] = s;
    result.m[2][0] = -s;
    result.m[2][2] = c;

    return result;
}

// Rotation autour de Z
Mat4x4 Mat4x4::RotationZ(float angle)
{
    Mat4x4 result = Identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[0][0] = c;
    result.m[0][1] = -s;
    result.m[1][0] = s;
    result.m[1][1] = c;

    return result;
}

// Multiplication de deux matrices
Mat4x4 Mat4x4::operator*(const Mat4x4& other) const
{
    Mat4x4 result;

    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 4; ++column)
        {
            result.m[row][column] = 0.0f;

            for (int k = 0; k < 4; ++k)
            {
                result.m[row][column] +=
                    m[row][k] * other.m[k][column];
            }
        }
    }

    return result;
}

// Transformation d'un point 3D
Vec3 Mat4x4::TransformPoint(const Vec3& point) const
{
    // Coordonnée homogène :
    // x, y, z, w = 1

    float x =
        m[0][0] * point.x +
        m[0][1] * point.y +
        m[0][2] * point.z +
        m[0][3];

    float y =
        m[1][0] * point.x +
        m[1][1] * point.y +
        m[1][2] * point.z +
        m[1][3];

    float z =
        m[2][0] * point.x +
        m[2][1] * point.y +
        m[2][2] * point.z +
        m[2][3];

    return Vec3(x, y, z);
}