#!/bin/bash

make clean
make
make run

files=$(find ./dist -type f -name '*.png')
for file in $files; do
  echo "$file" >> ./dist/items.txt
done
