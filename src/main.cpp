#include <iostream>
#include <string>
#include "ap.h"

int main(int argc, char *argv[]) {
  if (argc == 2 || argc == 3) { 
    std::string cadena;
    const std::string traza = "--traza";
    std::string file = argv[1];
    std::string path = "../test/";
    AP automata;

    if(argc == 2)
      automata = AP(path + file);
    else if(argc == 3 && std::string(argv[2]) == traza)
      automata = AP(path + file, true);
    else {
      std::cout << "Argumento incorrecto" << file;
      return 0;
    }

    automata.showInfo();
    std::cout << "\n\n";

    while(std::cin >> cadena && cadena != "exit") {
      automata.run(cadena);
      automata.reset();
      std::cout << "\n\n";
    }
  } else {
    std::cout << "introduzca fichero como argumento"; 
    return 0;
  }
}