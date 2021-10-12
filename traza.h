

class Traza {
 private:
  State* current;
  std::string cadena;
  Stack* pila;
  std::vector<Transition*> transiciones;
 public:
  Traza();
  ~Traza();
  void print();
};


print () {
  std::cout << current -> name << "\t" << cadena << "/t" << pila;
  for (auto t : transiciones) std::cout << t.name << " ";
}