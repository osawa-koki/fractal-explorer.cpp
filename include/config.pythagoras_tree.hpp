#ifndef config_pythagoras_tree_hpp
#define config_pythagoras_tree_hpp

#include <iostream>
#include <string>

using namespace std;

struct PythagorasTree {
  int width;
  int height;
  int color_from_hue;
  int color_upto_hue;
  int background_color_hex;
  int size;
  int degree;
  int depth;
  double left;
  double bottom;
  string output_file;
};

#endif
