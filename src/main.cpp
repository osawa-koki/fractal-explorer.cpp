#include "pugixml.hpp"
#include <iostream>
#include <string>

#include "config.hpp"
#include "commandline_parser.hpp"

int main() {

  Config* config_ptr = commandline_parser();
  Config config = *config_ptr;
  delete config_ptr;

  std::cout << "width: " << config.width << std::endl;
  std::cout << "height: " << config.height << std::endl;
  std::cout << "output_directory: " << config.output_directory << std::endl;

  std::cout << "===== ===== ===== Mandelbrot ===== ===== =====" << std::endl;
  std::cout << "x_min: " << config.mandelbrot.x_min << std::endl;
  std::cout << "x_max: " << config.mandelbrot.x_max << std::endl;
  std::cout << "y_min: " << config.mandelbrot.y_min << std::endl;
  std::cout << "y_max: " << config.mandelbrot.y_max << std::endl;
  std::cout << "threshold: " << config.mandelbrot.threshold << std::endl;
  std::cout << "max_iteration: " << config.mandelbrot.max_iterations << std::endl;
  std::cout << "color_hue: " << config.mandelbrot.color_hue << std::endl;
  std::cout << "background_color_hex: " << config.mandelbrot.background_color_hex << std::endl;
  std::cout << "output_file: " << config.mandelbrot.output_file << std::endl;

  return 0;
}
