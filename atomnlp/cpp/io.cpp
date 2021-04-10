#pragma once 

#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <vector>

using namespace std;
#include "io.h"

// =========================  File class implementation
bool File::iterate_file(string infile,
                        function<void(const string &)> callback) {
  ifstream in(infile.c_str());
  if (!in) {
    cerr << "Cannot open the File : " << infile << endl;
    return false;
  }
  string str;
  while (getline(in, str))
    callback(str);
  in.close();
  return true;
}

vector<string> File::read_to_vector(string &infile) {
  vector<string> vec_of_str;
  bool _ = iterate_file(infile,
                        [&](const string &str) { vec_of_str.push_back(str); });
  return vec_of_str;
}

vector<string> File::read_to_vector(const char *infile) {
  string str_f = infile;
  return read_to_vector(str_f);
}

// By default, read a file contents into a string.
string File::read(string &infile) {
  ifstream t(infile);
  stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}

string File::read(const char *infile) {
  string str_f(infile);
  return read(str_f);
}


// =========================  Bash class implementation
std::string Bash::run(std::string &cmd) {
  char buffer[128];
  string result = "";
  FILE *pipe = popen(cmd.c_str(), "r");
  if (!pipe)
    return "popen failed!";

  while (!feof(pipe))
    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;

  pclose(pipe);
  if(result.back() == '\n') result.pop_back(); // rstrip.
  return result;
}

std::string Bash::run(const char *cmd) {
  std::string cmd_str = cmd;
  return Bash::run(cmd_str);
}

// =========================  More class implementation

namespace _filesystem {
  bool exists(const std::string &name) { // Does file exist.
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
  }
}




