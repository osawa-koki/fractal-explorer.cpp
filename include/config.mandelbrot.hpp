#ifndef config_mandelbrot_hpp
#define config_mandelbrot_hpp

#include <iostream>
#include <string>

using namespace std;

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
  string output_file;
};

#endif
