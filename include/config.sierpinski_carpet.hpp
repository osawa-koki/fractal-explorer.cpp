#ifndef config_sierpinski_carpet_hpp
#define config_sierpinski_carpet_hpp

#include <iostream>
#include <string>

using namespace std;

struct SierpinskiCarpet {
  int width;
  int height;
  int color_hex;
  int filling_color_hex;
  int background_color_hex;
  int carpet_size;
  int max_iterations;
  string output_file;
};

#endif
