#include "Vec3.h"

// Constructeur par défaut
Vec3::Vec3()
    : x(0.0f), y(0.0f), z(0.0f)
{
}

// Constructeur avec valeurs
Vec3::Vec3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

// Addition
Vec3 Vec3::operator+(const Vec3& other) const
{
    return Vec3(
        x + other.x,
        y + other.y,
        z + other.z
    );
}

// Soustraction
Vec3 Vec3::operator-(const Vec3& other) const
{
    return Vec3(
        x - other.x,
        y - other.y,
        z - other.z
    );
}

// Multiplication par un scalaire
Vec3 Vec3::operator*(float scalar) const
{
    return Vec3(
        x * scalar,
        y * scalar,
        z * scalar
    );
}

// Division par un scalaire
Vec3 Vec3::operator/(float scalar) const
{
    return Vec3(
        x / scalar,
        y / scalar,
        z / scalar
    );
}

// Longueur du vecteur
float Vec3::Length() const
{
    return std::sqrt(
        x * x +
        y * y +
        z * z
    );
}

// Normalisation
Vec3 Vec3::Normalized() const
{
    float length = Length();

    // Un vecteur nul ne peut pas être normalisé.
    if (length == 0.0f)
    {
        return Vec3(0.0f, 0.0f, 0.0f);
    }

    return *this / length;
}

// Produit scalaire
float Dot(const Vec3& a, const Vec3& b)
{
    return
        a.x * b.x +
        a.y * b.y +
        a.z * b.z;
}