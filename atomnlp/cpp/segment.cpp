#include <assert.h>
#include <iostream>

#include "dofast.h"
#include "io.cpp"

class Segment {
public:
  Segment();
  std::vector<std::string> forward(string);
  std::vector<std::string> backward(string);
  std::vector<std::string> bidirectional(string);
  void add_ovv(string);

private:
  std::unordered_set<std::string> vocab;
};

// ----------------------------- implementation of segment class
Segment::Segment() {
  string infile = "../data/dict.txt";
  File::iterate_file(infile, [&](const string &str) {
    int idx = str.find_first_of('\t');
    std::string w = str.substr(0, idx);
    vocab.insert(w);
  });
}

void Segment::add_ovv(string ovv) { vocab.insert(ovv); }

std::vector<std::string> Segment::forward(string text) {
  // forward match segment method.
  assert(text.length() % 3 == 0); // assume all chars are Chinese.
  std::vector<std::string> res;
  size_t i = 0;

  while (i < text.length()) {
    int j = 3, maxlen = 3;
    while (i + j < len(text)) {
      j += 3;
      if (in(text.substr(i, j), vocab))
        maxlen = j;
    }
    // say(text.substr(i,j));
    res.push_back(text.substr(i, maxlen));
    i += maxlen;
  }
  return res;
}

void p(std::vector<std::string> &vs) {
  for (auto &s : vs)
    std::cout << s << " ";
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  using namespace std;
  say(">> Cpp segment algorithm << \n");
  Segment sm;
  sm.add_ovv("云服务");

  std::vector<std::string> res;
  res = sm.forward("当我谈论自由的时候，我在谈论些什么？");
  //   res = sm.forward("服务不要云服务。");

  if (argc > 1)
    res = sm.forward(string(argv[1]));
  p(res);
}
