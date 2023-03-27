#ifndef config_hpp
#define config_hpp

#include <iostream>
#include <string>

#include "config.mandelbrot.hpp"
#include "config.julia.hpp"
#include "config.tricorn.hpp"

struct Config {
  int width;
  int height;
  std::string output_directory;
  Mandelbrot* mandelbrot;
  Julia* julia;
  Tricorn* tricorn;
};

#endif
