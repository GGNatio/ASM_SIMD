#pragma once

#include "Vec3.h"

struct Mat4x4
{
    // Les 16 valeurs de la matrice
    float m[4][4];

    // Constructeur
    Mat4x4();

    // Création d'une matrice identité
    static Mat4x4 Identity();

    // Création d'une matrice de translation
    static Mat4x4 Translation(float x, float y, float z);

    // Création d'une rotation autour de l'axe X
    static Mat4x4 RotationX(float angle);

    // Création d'une rotation autour de l'axe Y
    static Mat4x4 RotationY(float angle);

    // Création d'une rotation autour de l'axe Z
    static Mat4x4 RotationZ(float angle);

    // Multiplication de deux matrices
    Mat4x4 operator*(const Mat4x4& other) const;

    // Transformation d'un point
    Vec3 TransformPoint(const Vec3& point) const;
};