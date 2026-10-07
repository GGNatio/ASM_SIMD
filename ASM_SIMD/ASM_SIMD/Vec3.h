#pragma once

#include <cmath>

struct Vec3
{
    float x;
    float y;
    float z;

    // Constructeurs
    Vec3();
    Vec3(float x, float y, float z);

    // Opérateurs
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    // Longueur du vecteur
    float Length() const;

    // Normalisation
    Vec3 Normalized() const;
};

// Produit scalaire
float Dot(const Vec3& a, const Vec3& b);