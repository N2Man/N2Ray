#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "rtweekend.h"
#include <iostream>



void write_color(/*std::ostream& out, */color pixel_color, int samples_per_pixel, unsigned char* data, int x, int y, int i, int j) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    data[(y - j - 1) * x * 3 + i * 3] = unsigned char(256 * clamp(r, 0.0, 0.999));
    data[(y - j - 1) * x * 3 + i * 3 + 1] = unsigned char(256 * clamp(g, 0.0, 0.999));
    data[(y - j - 1) * x * 3 + i * 3 + 2] = unsigned char(256 * clamp(b, 0.0, 0.999));

    // Write the translated [0,255] value of each color component.
    //out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
    //    << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
    //    << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif