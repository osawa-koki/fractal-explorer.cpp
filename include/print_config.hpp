#ifndef print_config_hpp
#define print_config_hpp

#include <iostream>
#include <string>

#include "config.hpp"

void print_config(const Config& config) {
  std::cout << "width: " << config.width << std::endl;
  std::cout << "height: " << config.height << std::endl;
  std::cout << "output_directory: " << config.output_directory << std::endl;

  std::cout << "===== ===== ===== Mandelbrot ===== ===== =====" << std::endl;
  std::cout << "width: " << config.mandelbrot->width << std::endl;
  std::cout << "height: " << config.mandelbrot->height << std::endl;
  std::cout << "x_min: " << config.mandelbrot->x_min << std::endl;
  std::cout << "x_max: " << config.mandelbrot->x_max << std::endl;
  std::cout << "y_min: " << config.mandelbrot->y_min << std::endl;
  std::cout << "y_max: " << config.mandelbrot->y_max << std::endl;
  std::cout << "threshold: " << config.mandelbrot->threshold << std::endl;
  std::cout << "max_iteration: " << config.mandelbrot->max_iterations << std::endl;
  std::cout << "color_hue: " << config.mandelbrot->color_hue << std::endl;
  std::cout << "output_file: " << config.mandelbrot->output_file << std::endl;

  std::cout << "===== ===== ===== Julia ===== ===== =====" << std::endl;
  std::cout << "width: " << config.julia->width << std::endl;
  std::cout << "height: " << config.julia->height << std::endl;
  std::cout << "x_min: " << config.julia->x_min << std::endl;
  std::cout << "x_max: " << config.julia->x_max << std::endl;
  std::cout << "y_min: " << config.julia->y_min << std::endl;
  std::cout << "y_max: " << config.julia->y_max << std::endl;
  std::cout << "cx: " << config.julia->cx << std::endl;
  std::cout << "cy: " << config.julia->cy << std::endl;
  std::cout << "threshold: " << config.julia->threshold << std::endl;
  std::cout << "max_iteration: " << config.julia->max_iterations << std::endl;
  std::cout << "color_hue: " << config.julia->color_hue << std::endl;
  std::cout << "output_file: " << config.julia->output_file << std::endl;
}

#endif
