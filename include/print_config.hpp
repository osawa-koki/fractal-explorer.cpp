#ifndef print_config_hpp
#define print_config_hpp

#include <iostream>
#include <string>

#include "config.hpp"

using namespace std;

void print_config(const Config& config) {
  cout << "width: " << config.width << endl;
  cout << "height: " << config.height << endl;
  cout << "output_directory: " << config.output_directory << endl;

  cout << "===== ===== ===== Mandelbrot ===== ===== =====" << endl;
  cout << "width: " << config.mandelbrot->width << endl;
  cout << "height: " << config.mandelbrot->height << endl;
  cout << "x_min: " << config.mandelbrot->x_min << endl;
  cout << "x_max: " << config.mandelbrot->x_max << endl;
  cout << "y_min: " << config.mandelbrot->y_min << endl;
  cout << "y_max: " << config.mandelbrot->y_max << endl;
  cout << "threshold: " << config.mandelbrot->threshold << endl;
  cout << "max_iteration: " << config.mandelbrot->max_iterations << endl;
  cout << "color_hue: " << config.mandelbrot->color_hue << endl;
  cout << "output_file: " << config.mandelbrot->output_file << endl;

  cout << "===== ===== ===== Julia ===== ===== =====" << endl;
  cout << "width: " << config.julia->width << endl;
  cout << "height: " << config.julia->height << endl;
  cout << "x_min: " << config.julia->x_min << endl;
  cout << "x_max: " << config.julia->x_max << endl;
  cout << "y_min: " << config.julia->y_min << endl;
  cout << "y_max: " << config.julia->y_max << endl;
  cout << "cx: " << config.julia->cx << endl;
  cout << "cy: " << config.julia->cy << endl;
  cout << "threshold: " << config.julia->threshold << endl;
  cout << "max_iteration: " << config.julia->max_iterations << endl;
  cout << "color_hue: " << config.julia->color_hue << endl;
  cout << "output_file: " << config.julia->output_file << endl;

  cout << "===== ===== ===== Tricorn ===== ===== =====" << endl;
  cout << "width: " << config.tricorn->width << endl;
  cout << "height: " << config.tricorn->height << endl;
  cout << "x_min: " << config.tricorn->x_min << endl;
  cout << "x_max: " << config.tricorn->x_max << endl;
  cout << "y_min: " << config.tricorn->y_min << endl;
  cout << "y_max: " << config.tricorn->y_max << endl;
  cout << "threshold: " << config.tricorn->threshold << endl;
  cout << "max_iteration: " << config.tricorn->max_iterations << endl;
  cout << "color_hue: " << config.tricorn->color_hue << endl;
  cout << "output_file: " << config.tricorn->output_file << endl;
}

#endif
