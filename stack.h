#include "alphabet.cpp"
#include <vector>  // no uso stack pq vector tiene mas funcionalidades y es mas comodo y no es necesario para emular una pila usar Stack

class Stack {
 private:
  Alphabet T;
  std::vector<std::string> stack;
 public:
  Stack();
  ~Stack();
  void pop();
  void push(std::string);
  bool empty();
  void reset();
  std::string top();
  friend class AP;  // cambiar y crear metodos o no es necesario?
};