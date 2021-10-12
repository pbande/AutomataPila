

class Transition {
 private:
  State* current;
  State* next;
  std::string input;
  std::string stack_pop;
  std::vector<std::string> stack_push;
 public:
  bool canTransitate(State*, Stack*, std::string);
};