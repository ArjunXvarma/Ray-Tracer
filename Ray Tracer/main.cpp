#include<fstream>
#include<cmath>
#include<iostream>

#include "Ray.h"
#include "Sphere.h"

void clamp255(Vector& col) {
    col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
    col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
    col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {

    const int H = 500;
    const int W = 500;

    FILE* output;

    const Vector white(255, 255, 255);
    const Vector black(0, 0, 0);
    const Vector red(255, 0, 0);
    const Vector orange(249, 127, 81);
    const Vector blue(27, 156, 252);
    const Vector yellow(234, 181, 67);

    const Sphere sphere(Vector(W * 0.5, H * 0.5, 69), 150);
    const Sphere light(Vector(50, 0, 20), 1);

    freopen_s(&output, "out.ppm", "w", stdout);
    std::cout << "P3\n" << W << ' ' << H << ' ' << "255\n";

    double t;
    Vector pix_col(black);

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            pix_col = black;

            const Ray ray(Vector(x, y, 0), Vector(0, 0, 1));
            if (sphere.intersect(ray, t)) {
                const Vector pi = ray.origin + ray.direction * t;
                const Vector L = light.center - pi;
                const Vector N = sphere.getNormal(pi);
                const double dt = dot(L.normalize(), N.normalize());

                pix_col = (yellow + white * dt) * 0.5;
                clamp255(pix_col);
            }
            std::cout << (int)pix_col.x << ' ' << (int)pix_col.y << ' ' << (int)pix_col.z << '\n';
        }
    }
}