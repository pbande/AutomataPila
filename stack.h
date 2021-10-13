#include "alphabet.cpp"
#include <vector>  // no uso stack pq vector tiene mas funcionalidades y para la traza etc necesito acceder a todos los valores e imprimirlos y con stack no se puede
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