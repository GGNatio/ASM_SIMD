#include <iostream>
#include <numbers>

#include "Vec3.h"
#include "Mat4x4.h"

int main()
{
    Vec3 point(1.0f, 0.0f, 0.0f);

    float angle = std::numbers::pi_v<float> / 2.0f;

    Mat4x4 rotation = Mat4x4::RotationZ(angle);

    Vec3 result = rotation.TransformPoint(point);

    std::cout << "Point original = ("
        << point.x << ", "
        << point.y << ", "
        << point.z << ")\n";

    std::cout << "Apres rotation Z 90 deg = ("
        << result.x << ", "
        << result.y << ", "
        << result.z << ")\n";

    return 0;
}