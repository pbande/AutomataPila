#include "alphabet.hpp"

Alphabet::Alphabet() {

}
Alphabet::~Alphabet() {

}

void Alphabet::add(std::string elem) {
  alphabet.push_back(elem);
}

bool Alphabet::check(std::string elem) {
  return std::find(alphabet.begin(), alphabet.end(), elem) != alphabet.end();
}