#include "state.cpp"

class Transition {
 private:
  State* current;
  State* next;
  std::string input;
  std::string stack_pop;
  std::vector<std::string> stack_push;
  int id;
 public:
  Transition();
  Transition(State*, std::string, std::string, State*, std::vector<std::string>, int);
  ~Transition();
  void print();
  //bool canTransitate(State*, Stack*, std::string);
};