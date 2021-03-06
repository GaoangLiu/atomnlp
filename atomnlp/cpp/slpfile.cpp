#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "fast.h"
#include "say.h"

class File {
private:
  /*
   * It will iterate through all the lines in file and
   * call the given callback on each line.
   */
  bool iterate_file(std::string file_name,
                    std::function<void(const std::string &)> callback) {
    std::ifstream in(file_name.c_str());
    if (!in) {
      std::cerr << "Cannot open the File : " << file_name << std::endl;
      return false;
    }
    std::string str;
    while (std::getline(in, str))
      callback(str);
    in.close();
    return true;
  }

public:
  /* Open file and store contents into vector line by line.
   */
  std::vector<std::string> read_to_vector(std::string &file_name) {
    std::vector<std::string> vec_of_str;
    bool _ = iterate_file(
        file_name, [&](const std::string &str) { vec_of_str.push_back(str); });
    return vec_of_str;
  }

  std::vector<std::string> read_to_vector(const char *file_name) {
    std::string str_f = file_name;
    return read_to_vector(str_f);
  }

  // By default, read a file contents into a string.
  std::string read(std::string &file_name) {
    std::ifstream t(file_name);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
  }

  std::string read(const char *file_name) {
    std::string str_f(file_name);
    return read(str_f);
  }
};

int main() {
  say("C++++++++++++++++++++++++++++++++++++++++++++++++++++++.");
  File f;
  // VS vs = f.read_to_vector("setup.py");
  // trav(v, vs) say(v);

  std::string ts = f.read("sample.txt");
  // say(ts);
}
