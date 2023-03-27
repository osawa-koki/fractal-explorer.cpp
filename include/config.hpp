#ifndef config_hpp
#define config_hpp

#include <iostream>
#include <string>

#include "config.mandelbrot.hpp"
#include "config.julia.hpp"
#include "config.tricorn.hpp"
#include "config.burning_ship.hpp"

using namespace std;

struct Config {
  int width;
  int height;
  string output_directory;
  Mandelbrot* mandelbrot;
  Julia* julia;
  Tricorn* tricorn;
  BurningShip* burning_ship;
};

#endif
