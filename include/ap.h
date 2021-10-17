#ifndef AP_H
#define AP_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

#include <vector>
#include "state.h"
#include "stack.h"
#include "transition.h"
#include "ap_info.h"

class AP {
 private:
  Alphabet E; // alfabeto de la entrada
  std::vector<State*> States; // conjunto de estados
  Stack stack; // pila
  State* initial_state; // estado inicial
  std::vector<Transition*> transitions; // conjunto de transiciones
  std::string tape; // cinta
  State* currentState; // estado actual
  bool traza; // modo traza

 public:
  AP();
  AP(std::string, bool traza_ = false); // por defecto no usa modo traza
  ~AP();
  void readData(std::string); // almacena datos del fichero
  void checkData(); // comprueba que todos los datos introducidos son correctos
  void showInfo(); // muestra informacion del automata
  std::vector<std::string> splitLine(std::string); // funcion para facilitar lectura
  State* findState(std::string); // busca estado por el id en el conjunto
  std::vector<Transition*> possibleMoves(State*); // devuelve transiciones posibles
  void transit(Transition*); // transita al estado siguiente
  void run(std::string); // comprueba si la cadena pertence al lenguaje
  void restore(Ap_info*); // vuelve el automata a un estado previo
  void reset(); // resetea automata al estado antes de introducir una cadena
  void printTraza(Ap_info*); // imprime la informacion actual del automata
};
#endif