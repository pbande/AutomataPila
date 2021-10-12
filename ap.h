#include <iostream>
#include <fstream>
#include <string>

class AP {
 private:
  Stack stack;
  Tape tape;
  // vector de State?
  // vector de transicion ??
 public:
  AP(std::string);
  ~AP();
  void readFile();
  //hahyquever gettransitions

};
