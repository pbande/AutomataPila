#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Alphabet {
 private:
  std::vector<std::string> alphabet;
 public:
  Alphabet();
  ~Alphabet();
  void add(std::string);
  bool check(std::string); // comprobar si elemento pertenece al lenguaje
  void print();
};
#endif