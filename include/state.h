#ifndef STATE_H
#define STATE_H
#include <string>

class State {
 private:
  bool final;
  std::string id;
 public:
  State();
  State(std::string, bool = false);
  ~State();
  void setFinal();
  bool isFinal();
  std::string getId();
};
#endif