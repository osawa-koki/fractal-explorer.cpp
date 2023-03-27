#ifndef config_mandelbrot_hpp
#define config_mandelbrot_hpp

#include <iostream>
#include <string>

struct Mandelbrot {
  int width;
  int height;
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  int threshold;
  int max_iterations;
  int color_hue;
  int background_color_hex;
  std::string output_file;
};

#endif
