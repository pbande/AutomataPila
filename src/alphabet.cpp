#include "alphabet.h"

Alphabet::Alphabet() {
}
Alphabet::~Alphabet() {

}

void Alphabet::add(std::string elem) {
  alphabet.push_back(elem);
}

bool Alphabet::check(std::string elem) {
  if(elem == ".") return true;
  return std::find(alphabet.begin(), alphabet.end(), elem) != alphabet.end();
}

void Alphabet::print() {
  for(auto token : alphabet)
    std::cout << token << " ";
  std::cout << "\n";
}