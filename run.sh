#!/bin/bash

make clean
make
make run

files=$(find ./dist -type f)
for file in $files; do
  echo "$file" >> ./dist/items.txt
done
