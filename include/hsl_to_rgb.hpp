#ifndef hsl_to_rgb_hpp
#define hsl_to_rgb_hpp

#include <cmath>
#include <array>
#include <iostream>

#define COLOR_MAX 255

std::array<int, 3> hsl_to_rgb(double h, double s, double l) {
  double max = l + (s * (1 - std::abs((2 * l) - 1)) / 2);
  double min = l - (s * (1 - std::abs((2 * l) - 1)) / 2);

  std::array<int, 3> rgb;
  int i = static_cast<int>(h / 60);

  switch (i) {
    case 0:
    case 6:
      rgb[0] = max * COLOR_MAX;
      rgb[1] = (min + (max - min) * (h / 60)) * COLOR_MAX;
      rgb[2] = min * COLOR_MAX;
      break;
    case 1:
      rgb[0] = (min + (max - min) * (120 - h / 60)) * COLOR_MAX;
      rgb[1] = max * COLOR_MAX;
      rgb[2] = min * COLOR_MAX;
      break;
    case 2:
      rgb[0] = min * COLOR_MAX;
      rgb[1] = max * COLOR_MAX;
      rgb[2] = (min + (max - min) * (h - 120 / 60)) * COLOR_MAX;
      break;
    case 3:
      rgb[0] = min * COLOR_MAX;
      rgb[1] = (min + (max - min) * (240 - h / 60)) * COLOR_MAX;
      rgb[2] = max * COLOR_MAX;
      break;
    case 4:
      rgb[0] = (min + (max - min) * (h - 240 / 60)) * COLOR_MAX;
      rgb[1] = min * COLOR_MAX;
      rgb[2] = max * COLOR_MAX;
      break;
    case 5:
      rgb[0] = max * COLOR_MAX;
      rgb[1] = min * COLOR_MAX;
      rgb[2] = (min + (max - min) * (360 - h / 60)) * COLOR_MAX;
      break;
  }

  return rgb;
}

#endif
