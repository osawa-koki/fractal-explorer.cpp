#ifndef config_burning_ship_hpp
#define config_burning_ship_hpp

#include <iostream>
#include <string>

using namespace std;

struct BurningShip {
  int width;
  int height;
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  int threshold;
  int max_iterations;
  int color_hue;
  string output_file;
};

#endif
