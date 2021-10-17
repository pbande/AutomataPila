#ifndef STACK_H
#define STACK_H
#include <vector>  
#include "alphabet.h"

class Stack {
 private:
  Alphabet T; // alfabeto de la pila
  std::vector<std::string> stack;
  std::string S; // simbolo de inicio de la pila
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
  friend class AP;
};
#endif