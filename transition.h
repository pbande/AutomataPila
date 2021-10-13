#include "state.cpp"

class Alphbet;

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
  bool isNull();
  // seria mejor un metodo bool al que le paso ambos alfabetos y devuelve si es correcto o no.. IMPLEMENTAR SI HAY TIEMPO
  bool checkAlphabet(Alphabet&, Alphabet&);
  std::string getInput();
  std::string getPop();
  std::vector<std::string> getPush();
  void print();
  int getId();
  //bool canTransitate(State*, Stack*, std::string);
};