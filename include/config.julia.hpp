#ifndef config_julia_hpp
#define config_julia_hpp

#include <iostream>
#include <string>

struct Julia {
  int width;
  int height;
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  double cx;
  double cy;
  int threshold;
  int max_iterations;
  int color_hue;
  std::string output_file;
};

#endif
