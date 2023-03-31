#ifndef config_barnsley_fern_hpp
#define config_barnsley_fern_hpp

#include <iostream>
#include <string>

using namespace std;

struct BarnsleyFern {
  int width;
  int height;
  double size_x;
  double size_y;
  double start_x;
  double start_y;
  double zoom;
  int max_iterations;
  int color_hex;
  int background_color_hex;
  string output_file;
};

#endif
