#include "alphabet.h"

class Stack {
 private:
  Alphabet T;
  std::stack<std::string> stack;
 public:
  Stack();
  ~Stack();
  void pop();
  void push(std::string);
  bool empty();
  void reset();
  int top();
};