#ifndef config_hpp
#define config_hpp

#include <iostream>
#include <string>

#include "config.mandelbrot.hpp"
#include "config.julia.hpp"
#include "config.tricorn.hpp"
#include "config.burning_ship.hpp"
#include "config.barnsley_fern.hpp"
#include "config.pythagoras_tree.hpp"
#include "config.recursive_tree.hpp"

using namespace std;

struct Config {
  int width;
  int height;
  string output_directory;
  Mandelbrot* mandelbrot;
  Julia* julia;
  Tricorn* tricorn;
  BurningShip* burning_ship;
  BarnsleyFern* barnsley_fern;
  PythagorasTree* pythagoras_tree;
  RecursiveTree* recursive_tree;
};

#endif
