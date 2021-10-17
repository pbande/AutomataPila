#ifndef STATE_H
#define STATE_H
#include <string>

class State {
 private:
  bool final; 
  std::string id; // nombre del estado
 public:
  State();
  State(std::string, bool = false);
  ~State();
  void setFinal(); // no lo uso pq es APv
  bool isFinal(); // no lo uso pq es APv
  std::string getId(); 
};
#endif