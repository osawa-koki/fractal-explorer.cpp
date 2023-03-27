#include "pugixml.hpp"
#include <iostream>
#include <string>

#include "config.hpp"
#include "commandline_parser.hpp"
#include "print_config.hpp"

int main() {

  Config* config_ptr = commandline_parser();
  Config config = *config_ptr;
  
  delete config_ptr;
  delete config.mandelbrot;

  print_config(config);

  return 0;
}
