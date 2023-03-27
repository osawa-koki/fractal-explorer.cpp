#ifndef hsl_to_rgb_hpp
#define hsl_to_rgb_hpp

#include <cmath>
#include <array>
#include <iostream>

#include "const.hpp"

using namespace std;

array<int, 3> hsl_to_rgb(double h, double s, double l) {
  double max = l + (s * (1 - abs((2 * l) - 1)) / 2);
  double min = l - (s * (1 - abs((2 * l) - 1)) / 2);

  array<int, 3> rgb;
  int i = static_cast<int>(h / 60);

  switch (i) {
    case 0:
    case 6:
      rgb[0] = max * MAX_COLOR_VALUE;
      rgb[1] = (min + (max - min) * (h / 60)) * MAX_COLOR_VALUE;
      rgb[2] = min * MAX_COLOR_VALUE;
      break;
    case 1:
      rgb[0] = (min + (max - min) * (120 - h / 60)) * MAX_COLOR_VALUE;
      rgb[1] = max * MAX_COLOR_VALUE;
      rgb[2] = min * MAX_COLOR_VALUE;
      break;
    case 2:
      rgb[0] = min * MAX_COLOR_VALUE;
      rgb[1] = max * MAX_COLOR_VALUE;
      rgb[2] = (min + (max - min) * (h - 120 / 60)) * MAX_COLOR_VALUE;
      break;
    case 3:
      rgb[0] = min * MAX_COLOR_VALUE;
      rgb[1] = (min + (max - min) * (240 - h / 60)) * MAX_COLOR_VALUE;
      rgb[2] = max * MAX_COLOR_VALUE;
      break;
    case 4:
      rgb[0] = (min + (max - min) * (h - 240 / 60)) * MAX_COLOR_VALUE;
      rgb[1] = min * MAX_COLOR_VALUE;
      rgb[2] = max * MAX_COLOR_VALUE;
      break;
    case 5:
      rgb[0] = max * MAX_COLOR_VALUE;
      rgb[1] = min * MAX_COLOR_VALUE;
      rgb[2] = (min + (max - min) * (360 - h / 60)) * MAX_COLOR_VALUE;
      break;
  }

  return rgb;
}

#endif
