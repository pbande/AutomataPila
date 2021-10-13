#include "stack.h"

Stack::Stack() {

}
Stack::~Stack() {

}

void Stack::pop() {
  stack.pop_back();
}

void Stack::push(std::string elem) {  // mirar cuando pusheo varios elementos
  stack.push_back(elem);
}


bool Stack::empty() {
  return stack.empty();
}

void Stack::reset() {
  stack.resize(0);
}

std::string Stack::top() {
  return stack.front();
}