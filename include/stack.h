#ifndef STACK_H
#define STACK_H
#include <vector>  
#include "alphabet.h"

class Stack {
 private:
  Alphabet T;
  std::vector<std::string> stack;
  std::string S;
 public:
  Stack();
  Stack(std::string);
  ~Stack();
  void pop();
  void push(std::string);
  void push(std::vector<std::string>);
  bool empty();
  void reset();
  void setStart(std::string);
  bool check();
  void print();
  std::string top();
  friend class AP;  // cambiar y crear metodos o no es necesario?
};
#endif