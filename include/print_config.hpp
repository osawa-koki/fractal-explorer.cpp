#ifndef print_config_hpp
#define print_config_hpp

#include <iostream>
#include <string>

#include "config.hpp"

using namespace std;

void print_config(const Config& config) {
  cout << "width: " << config.width << endl;
  cout << "height: " << config.height << endl;
  cout << "output_directory: " << config.output_directory << endl;

  cout << "===== ===== ===== Mandelbrot ===== ===== =====" << endl;
  cout << "width: " << config.mandelbrot->width << endl;
  cout << "height: " << config.mandelbrot->height << endl;
  cout << "x_min: " << config.mandelbrot->x_min << endl;
  cout << "x_max: " << config.mandelbrot->x_max << endl;
  cout << "y_min: " << config.mandelbrot->y_min << endl;
  cout << "y_max: " << config.mandelbrot->y_max << endl;
  cout << "threshold: " << config.mandelbrot->threshold << endl;
  cout << "max_iteration: " << config.mandelbrot->max_iterations << endl;
  cout << "color_hue: " << config.mandelbrot->color_hue << endl;
  cout << "output_file: " << config.mandelbrot->output_file << endl;

  cout << "===== ===== ===== Julia ===== ===== =====" << endl;
  cout << "width: " << config.julia->width << endl;
  cout << "height: " << config.julia->height << endl;
  cout << "x_min: " << config.julia->x_min << endl;
  cout << "x_max: " << config.julia->x_max << endl;
  cout << "y_min: " << config.julia->y_min << endl;
  cout << "y_max: " << config.julia->y_max << endl;
  cout << "cx: " << config.julia->cx << endl;
  cout << "cy: " << config.julia->cy << endl;
  cout << "threshold: " << config.julia->threshold << endl;
  cout << "max_iteration: " << config.julia->max_iterations << endl;
  cout << "color_hue: " << config.julia->color_hue << endl;
  cout << "output_file: " << config.julia->output_file << endl;

  cout << "===== ===== ===== Tricorn ===== ===== =====" << endl;
  cout << "width: " << config.tricorn->width << endl;
  cout << "height: " << config.tricorn->height << endl;
  cout << "x_min: " << config.tricorn->x_min << endl;
  cout << "x_max: " << config.tricorn->x_max << endl;
  cout << "y_min: " << config.tricorn->y_min << endl;
  cout << "y_max: " << config.tricorn->y_max << endl;
  cout << "threshold: " << config.tricorn->threshold << endl;
  cout << "max_iteration: " << config.tricorn->max_iterations << endl;
  cout << "color_hue: " << config.tricorn->color_hue << endl;
  cout << "output_file: " << config.tricorn->output_file << endl;

  cout << "===== ===== ===== Burning Ship ===== ===== =====" << endl;
  cout << "width: " << config.burning_ship->width << endl;
  cout << "height: " << config.burning_ship->height << endl;
  cout << "x_min: " << config.burning_ship->x_min << endl;
  cout << "x_max: " << config.burning_ship->x_max << endl;
  cout << "y_min: " << config.burning_ship->y_min << endl;
  cout << "y_max: " << config.burning_ship->y_max << endl;
  cout << "threshold: " << config.burning_ship->threshold << endl;
  cout << "max_iteration: " << config.burning_ship->max_iterations << endl;
  cout << "color_hue: " << config.burning_ship->color_hue << endl;
  cout << "output_file: " << config.burning_ship->output_file << endl;

  cout << "===== ===== ===== Barnsley Fern ===== ===== =====" << endl;
  cout << "width: " << config.barnsley_fern->width << endl;
  cout << "height: " << config.barnsley_fern->height << endl;
  cout << "size_x: " << config.barnsley_fern->size_x << endl;
  cout << "size_y: " << config.barnsley_fern->size_y << endl;
  cout << "start_x: " << config.barnsley_fern->start_x << endl;
  cout << "start_y: " << config.barnsley_fern->start_y << endl;
  cout << "zoom: " << config.barnsley_fern->zoom << endl;
  cout << "max_iterations: " << config.barnsley_fern->max_iterations << endl;
  cout << "color_hue: " << config.barnsley_fern->color_hue << endl;
  cout << "background_color_hex: " << config.barnsley_fern->background_color_hex << endl;
  cout << "output_file: " << config.barnsley_fern->output_file << endl;

  cout << "===== ===== ===== Pythagoras Tree ===== ===== =====" << endl;
  cout << "width: " << config.pythagoras_tree->width << endl;
  cout << "height: " << config.pythagoras_tree->height << endl;
  cout << "color_from_hue: " << config.pythagoras_tree->color_from_hue << endl;
  cout << "color_upto_hue: " << config.pythagoras_tree->color_upto_hue << endl;
  cout << "background_color_hex: " << config.pythagoras_tree->background_color_hex << endl;
  cout << "size: " << config.pythagoras_tree->size << endl;
  cout << "degree: " << config.pythagoras_tree->degree << endl;
  cout << "depth: " << config.pythagoras_tree->depth << endl;
  cout << "left: " << config.pythagoras_tree->left << endl;
  cout << "bottom: " << config.pythagoras_tree->bottom << endl;
  cout << "output_file: " << config.pythagoras_tree->output_file << endl;
}

#endif
