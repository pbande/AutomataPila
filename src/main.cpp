#include <iostream>
#include <string>
#include "ap.h"

int main(int argc, char *argv[]) {
  if (argc != 2) { 
    std::cout << "introduzca fichero como argumento"; 
    return 0;
  }
  std::string file = argv[1];
  AP automata(file);
  automata.showInfo();
  std::cout << "\n\n";
  std::string cadena;

  while(std::cin >> cadena && cadena != "exit") {
    automata.run(cadena);
    automata.reset();
    std::cout << "\n\n";
  }
}