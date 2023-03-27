#ifndef join_path_hpp
#define join_path_hpp

#include <iostream>
#include <string>

using namespace std;

string join_path(const string& dir_path, const string& file_name) {
  string full_path = dir_path;
  if (dir_path.back() != '/') {
    full_path += '/';
  }
  full_path += file_name;
  return full_path;
}

#endif
