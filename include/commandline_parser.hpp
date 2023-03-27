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
  mandelbrot->background_color_hex = std::stoi(mandelbrot_node.child("background_color_hex").child_value(), nullptr, 16);
  mandelbrot->output_file = mandelbrot_node.child("output_file").child_value();
  config->mandelbrot = mandelbrot;

  return config;
}
