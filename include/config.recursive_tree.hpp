#ifndef config_recursive_tree_hpp
#define config_recursive_tree_hpp

#include <iostream>
#include <string>

using namespace std;

struct RecursiveTree {
  int width;
  int height;
  int shrink;
  int length;
  int angle;
  int max_iterations;
  int stroke_width;
  int color_hex;
  int background_color_hex;
  string output_file;
};

#endif
