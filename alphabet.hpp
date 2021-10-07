#include <iostream>
#include <string>
#include <vector>

class Alphabet {
 private:
  std::vector<std::string> alphabet;
 public:
  Alphabet();
  ~Alphabet();
  void add(std::string);
  bool check(std::string);
};