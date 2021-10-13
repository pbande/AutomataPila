#include <string>

class State {
 private:
  bool final;
  std::string id;
 public:
  State();
  State(std::string, bool);
  ~State();
  void setFinal();
  bool isFinal();
  std::string getId();
};