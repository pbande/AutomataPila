#include "stack.h"

Stack::Stack() {

}
Stack::~Stack() {

}

void Stack::pop() {
  stack.pop();
}

void Stack::push(std::string elem) {  // mirar cuando pusheo varios elementos
  stack.push(elem);
}


bool Stack::empty() {
  return stack.empty();
}

void Stack::reset() {
  stack.resize(0);
}

int Stack::top() {
  return stack.top();
}