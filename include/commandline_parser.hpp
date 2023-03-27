#include "pugixml.hpp"
#include <iostream>
#include <string>

#include "config.hpp"

Config* commandline_parser() {
  // XMLファイルを開く
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file("config.xml");

  if (!result) {
    std::cerr << "XMLファイルの読み込みに失敗しました。" << std::endl;
    std::cerr << result.description() << std::endl;
    return nullptr;
  }

  // ルート要素を取得する
  pugi::xml_node config_node = doc.child("config");
  if (config_node.empty()) {
    std::cerr << "ルート要素が見つかりませんでした。" << std::endl;
    return nullptr;
  }

  Config* config = new Config();

  pugi::xml_node width_node = config_node.child("width");
  pugi::xml_node height_node = config_node.child("height");
  pugi::xml_node output_directory_node = config_node.child("output_directory");

  int width = std::stoi(width_node.child_value());
  int height = std::stoi(height_node.child_value());

  config->width = width;
  config->height = height;
  config->output_directory = output_directory_node.child_value();

  pugi::xml_node mandelbrot_node = config_node.child("mandelbrot");
  Mandelbrot* mandelbrot = new Mandelbrot();
  mandelbrot->width = width;
  mandelbrot->height = height;
  mandelbrot->x_min = std::stod(mandelbrot_node.child("x_min").child_value());
  mandelbrot->x_max = std::stod(mandelbrot_node.child("x_max").child_value());
  mandelbrot->y_min = std::stod(mandelbrot_node.child("y_min").child_value());
  mandelbrot->y_max = std::stod(mandelbrot_node.child("y_max").child_value());
  mandelbrot->threshold = std::stoi(mandelbrot_node.child("threshold").child_value());
  mandelbrot->max_iterations = std::stoi(mandelbrot_node.child("max_iterations").child_value());
  mandelbrot->color_hue = std::stoi(mandelbrot_node.child("color_hue").child_value());
  mandelbrot->output_file = mandelbrot_node.child("output_file").child_value();
  config->mandelbrot = mandelbrot;

  pugi::xml_node julia_node = config_node.child("julia");
  Julia* julia = new Julia();
  julia->width = width;
  julia->height = height;
  julia->x_min = std::stod(julia_node.child("x_min").child_value());
  julia->x_max = std::stod(julia_node.child("x_max").child_value());
  julia->y_min = std::stod(julia_node.child("y_min").child_value());
  julia->y_max = std::stod(julia_node.child("y_max").child_value());
  julia->cx = std::stod(julia_node.child("cx").child_value());
  julia->cy = std::stod(julia_node.child("cy").child_value());
  julia->threshold = std::stoi(julia_node.child("threshold").child_value());
  julia->max_iterations = std::stoi(julia_node.child("max_iterations").child_value());
  julia->color_hue = std::stoi(julia_node.child("color_hue").child_value());
  julia->output_file = julia_node.child("output_file").child_value();
  config->julia = julia;

  pugi::xml_node tricorn_node = config_node.child("tricorn");
  Tricorn* tricorn = new Tricorn();
  tricorn->width = width;
  tricorn->height = height;
  tricorn->x_min = std::stod(tricorn_node.child("x_min").child_value());
  tricorn->x_max = std::stod(tricorn_node.child("x_max").child_value());
  tricorn->y_min = std::stod(tricorn_node.child("y_min").child_value());
  tricorn->y_max = std::stod(tricorn_node.child("y_max").child_value());
  tricorn->threshold = std::stoi(tricorn_node.child("threshold").child_value());
  tricorn->max_iterations = std::stoi(tricorn_node.child("max_iterations").child_value());
  tricorn->color_hue = std::stoi(tricorn_node.child("color_hue").child_value());
  tricorn->output_file = tricorn_node.child("output_file").child_value();
  config->tricorn = tricorn;

  return config;
}
