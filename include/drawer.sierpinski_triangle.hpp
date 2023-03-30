#ifndef drawer_sierpinski_triangle_hpp
#define drawer_sierpinski_triangle_hpp

#include <iostream>
#include <string>
#include <png.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "const.hpp"
#include "config.sierpinski_triangle.hpp"
#include "hsl_to_rgb.hpp"
#include "interface.coord.hpp"
#include "routine.draw_polygon.hpp"
#include "interface.rgb.hpp"
#include "interface.hsl.hpp"

using namespace std;

namespace sierpinski_triangle {

  void drawer(const SierpinskiTriangle& config) {
    // 画像の幅と高さを指定する
    int width = config.width;
    int height = config.height;

    int color = config.color_hex;
    int filling_color = config.filling_color_hex;
    int background_color = config.background_color_hex;

    int triangle_size = config.triangle_size;
    int max_iterations = config.max_iterations;

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

    int size = width * triangle_size / 100;
    int start = (height - (sqrt(3) * height * triangle_size / 100 / 2)) / 2;

    int p1_x = cos(240 * M_PI / 180) * size / 2 + width / 2;
    int p1_y = start - sin(240 * M_PI / 180) * size / 2;
    int p2_x = cos(-60 * M_PI / 180) * size / 2 + p1_x;
    int p2_y = p1_y - sin(-60 * M_PI / 180) * size / 2;

    int _p2_x = cos(240 * M_PI / 180) * size + width / 2;
    int _p2_y = start - sin(240 * M_PI / 180) * size;

    {
      std::vector<Coord> vertices = {
        Coord{width / 2, start},
        Coord{_p2_x, _p2_y},
        Coord{_p2_x + size, _p2_y}
      };
      draw_polygon(row_pointers, color, vertices);
    }
    {
      std::vector<Coord> vertices = {
        Coord{p1_x, p1_y},
        Coord{p2_x, p2_y},
        Coord{p1_x + size / 2, p1_y}
      };
      draw_polygon(row_pointers, filling_color, vertices);
    }

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
