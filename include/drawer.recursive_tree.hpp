#ifndef drawer_recursive_tree_hpp
#define drawer_recursive_tree_hpp

#include <iostream>
#include <string>
#include <png.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "const.hpp"
#include "config.recursive_tree.hpp"
#include "hsl_to_rgb.hpp"
#include "interface.coord.hpp"
#include "routine.draw_polyline.hpp"
#include "interface.rgb.hpp"
#include "interface.hsl.hpp"

using namespace std;

namespace recursive_tree {

  struct NextPointStruct {
    int x;
    int y;
    int degree;
  };

  struct GlobalConfig {
    int width;
    int height;
    int shrink;
    int length;
    int angle;
    int max_iterations;
    int color;
    int stroke_width;
    int stroke_diff;
  };

  void rec_draw(png_bytep *row_pointers, GlobalConfig* global_config, int x, int y, int degree, int n) {
    if (global_config->max_iterations < n) return;

    int len = (int)(pow(global_config->shrink / 100.0, n) * (global_config->width + global_config->height) / 2) * global_config->length / 100.0;
    vector<NextPointStruct> moved = {};

    // 右側
    {
      int ang = (360 + degree - global_config->angle) % 360;
      int moved_x = x + cos(ang * M_PI / 180.0) * len;
      int moved_y;
      if (ang == 90) {
        moved_y = y - len;
      } else if (ang == 270) {
        moved_y = y + len;
      } else {
        moved_y = y + tan(ang * M_PI / 180.0) * (x - moved_x);
      }
      NextPointStruct tmp = {moved_x, moved_y, ang};
      moved.push_back(tmp);
    }

    // 左側
    {
      int ang = (degree + global_config->angle) % 360;
      int moved_x = x + cos(ang * M_PI / 180.0) * len;
      int moved_y;
      if (ang == 90) {
        moved_y = y - len;
      } else if (ang == 270) {
        moved_y = y + len;
      } else {
        moved_y = y + tan(ang * M_PI / 180.0) * (x - moved_x);
      }
      NextPointStruct tmp = {moved_x, moved_y, ang};
      moved.push_back(tmp);
    }

    for (auto m : moved) {
      vector<Coord> vertices {
        {x - global_config->stroke_diff, y - global_config->stroke_diff},
        {x + global_config->stroke_diff, y + global_config->stroke_diff},
        {m.x - global_config->stroke_diff, m.y - global_config->stroke_diff},
        {m.x + global_config->stroke_diff, m.y + global_config->stroke_diff}
      };
      draw_polyline(row_pointers, global_config->color, vertices);
      rec_draw(row_pointers, global_config, m.x, m.y, m.degree, n + 1);
    }
  }

  void drawer(const RecursiveTree& config) {
    // 画像の幅と高さを指定する
    int width = config.width;
    int height = config.height;

    int shrink = config.shrink;
    int length = config.length;
    int angle = config.angle;
    int max_iterations = config.max_iterations;
    int stroke_width = config.stroke_width;
    int color = config.color_hex;
    int background_color = config.background_color_hex;

    GlobalConfig* global_config = new GlobalConfig();
    global_config->width = width;
    global_config->height = height;
    global_config->shrink = shrink;
    global_config->length = length;
    global_config->angle = angle;
    global_config->max_iterations = max_iterations;
    global_config->color = color;
    global_config->stroke_width = stroke_width;
    global_config->stroke_diff = stroke_width / 2;

    // 画像のデータを格納する配列を確保する
    png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
    for (int y = 0; y < height; y++)
    {
      row_pointers[y] = (png_byte *)malloc(sizeof(png_byte) * width * 4);
    }

    for (int y = 0; y < height; y++)
    {
      png_bytep row = row_pointers[y];
      for (int x = 0; x < width; x++)
      {
        png_bytep px = &(row[x * 4]);
        px[0] = (background_color >> 16) & 0xff;
        px[1] = (background_color >> 8) & 0xff;
        px[2] = (background_color >> 0) & 0xff;
        px[3] = MAX_COLOR_VALUE;
      }
    }

    vector<Coord> vertices {
      {width / 2 - global_config->stroke_diff, height},
      {width / 2 + global_config->stroke_diff, height},
      {width / 2 - global_config->stroke_diff, height - (height * length / 100.0)},
      {width / 2 + global_config->stroke_diff, height - (height * length / 100.0)}
    };
    draw_polyline(row_pointers, global_config->color, vertices);

    rec_draw(row_pointers, global_config, width / 2, height - (height * length / 100.0), 90, 0);
    delete global_config;

    // 画像をファイルに出力する
    ofstream output_file(config.output_file, ios::binary);
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info = png_create_info_struct(png);
    png_set_write_fn(
        png, &output_file, [](png_structp png, png_bytep data, png_size_t length)
        { ((ostream *)png_get_io_ptr(png))->write((char *)data, length); },
        nullptr);
    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png, info);
    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    // メモリを解放する
    for (int y = 0; y < height; y++)
    {
      free(row_pointers[y]);
    }
    free(row_pointers);

    return;
  }

}

#endif
