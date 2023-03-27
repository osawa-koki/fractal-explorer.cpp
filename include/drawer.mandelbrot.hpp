#ifndef drawer_mandelbrot_hpp
#define drawer_mandelbrot_hpp

#include <iostream>
#include <string>
#include <png.h>
#include <iostream>
#include <fstream>

#include "config.mandelbrot.hpp"
#include "hsl_to_rgb.hpp"

#define MAX_COLOR_VALUE 255

void mandelbrot_drawer(const Mandelbrot& config) {
  // 画像の幅と高さを指定する
  int width = config.width;
  int height = config.height;

  double x_min = config.x_min;
  double x_max = config.x_max;
  double y_min = config.y_min;
  double y_max = config.y_max;

  int color = config.color_hue;

  int max_iterations = config.max_iterations;

  // 画像のデータを格納する配列を確保する
  png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);
  for (int y = 0; y < height; y++)
  {
    row_pointers[y] = (png_byte *)malloc(sizeof(png_byte) * width * 4);
  }

  // マンデルブロ集合を描写する
  for (int y = 0; y < height; y++)
  {
    png_bytep row = row_pointers[y];
    for (int x = 0; x < width; x++)
    {
      png_bytep px = &(row[x * 4]);

      // マンデルブロ集合の計算を行う
      double x0 = x_min + (x_max - x_min) * x / width;
      double y0 = y_min + (y_max - y_min) * y / height;
      double x1 = 0.0;
      double y1 = 0.0;
      int i = 0;
      while (x1 * x1 + y1 * y1 <= 2 * 2 && i < max_iterations)
      {
        double x2 = x1 * x1 - y1 * y1 + x0;
        double y2 = 2 * x1 * y1 + y0;
        x1 = x2;
        y1 = y2;
        i++;
      }

      // マンデルブロ集合の計算結果を色に変換する
      int color = i * MAX_COLOR_VALUE / max_iterations;
      std::array<int, 3> rgb = hsl_to_rgb(color, 100, 50);
      px[0] = rgb[0];
      px[1] = rgb[1];
      px[2] = rgb[2];
      px[3] = MAX_COLOR_VALUE;
    }
  }

  // 画像をファイルに出力する
  std::ofstream output_file(config.output_file, std::ios::binary);
  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop info = png_create_info_struct(png);
  png_set_write_fn(
      png, &output_file, [](png_structp png, png_bytep data, png_size_t length)
      { ((std::ostream *)png_get_io_ptr(png))->write((char *)data, length); },
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

#endif