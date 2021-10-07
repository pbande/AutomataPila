#include <iostream>
#include <fstream>
#include <string>
#include "ap.hpp"

int main() {
  std::string definition;
  std::cout << "\nFile: ";
  std::cin >> definition;
  AP automata = AP(definition + ".txt");
  // cargo gramática 1vez
  // voy cargando cadenas por teclado  
}