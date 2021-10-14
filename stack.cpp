#include "stack.h"

Stack::Stack() {
}

Stack::Stack(std::string s_) {
  S = s_;
  stack.push_back(S);
}

Stack::~Stack() {
}

void Stack::pop() {
  stack.pop_back();
}

void Stack::push(std::string elem) {  // mirar cuando pusheo varios elementos
  stack.push_back(elem);
}

void Stack::push(std::vector<std::string> elems) {
  for(int it = elems.size() - 1; it >= 0; it--) // tengo que insertarlos al revés para que funcione como pila en el vector
    if(elems[it] != ".")
      stack.push_back(elems[it]);
}

bool Stack::empty() {
  return stack.empty();
}

void Stack::reset() {
  stack.resize(0);
  stack.push_back(S);
}

std::string Stack::top() {
  return stack.back();
}

void Stack::setStart(std::string s_) {
  S = s_;
  stack.push_back(S);
}

bool Stack::check() {
  return T.check(S);
}

void Stack::print() {
  for(int it = stack.size() - 1; it >= 0; it--)
    std::cout << stack[it] << " ";
}