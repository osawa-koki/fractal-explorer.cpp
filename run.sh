#!/bin/bash

target_dir="./dist"
target_file="$target_dir/items.txt"
rm -f "$target_file"

make clean
make
make run

files=$(find $target_dir -type f -name '*.png')
for file in $files; do
  echo "$file" >> "$target_file"
done
