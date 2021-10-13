#include "ap.h"

AP::AP() {

}
AP::AP(std::string file) {
  readData(file);
  checkData();
  showInfo();

}

AP::~AP() {
  
}

State* AP::findState(std::string state_) {
  for(auto state : States)
      if(state -> getId() == state_) 
        return state;
  std::cout << "error estado funcion findstate\n";
  return NULL;
}

std::vector<std::string> AP::splitLine(std::string line) {
  std::istringstream ss(line); 
  std::string split;
  std::vector<std::string> processedLine;
  while(std::getline(ss, split, ' '))
    processedLine.push_back(split);
  return processedLine;
}

void AP::readData(std::string file) {   // Hago metodo para devolver las lineas en vectores / array?
  std::ifstream apFile(file);
  std::string line;

  if(apFile.is_open()) {
    while(std::getline(apFile, line) && line[0] == '#') continue; // ignore first commented lines

    for(auto state : splitLine(line))
      States.push_back(new State(state));
    
    std::getline(apFile, line);
    for(auto token : splitLine(line))
      E.add(token);
    
    std::getline(apFile, line);
    for(auto token : splitLine(line))
      stack.T.add(token);
    
    std::getline(apFile, line);
    initial_state = findState(line);
      
    std::getline(apFile, line);
    stack.setStart(line);

    std::vector<std::string> tline;
    std::vector<std::string> stack_push;
    int id = 1;
    while(std::getline(apFile, line)) {
      tline = splitLine(line);
      stack_push = std::vector<std::string> (tline.begin() + 4, tline.end());
      transitions.push_back(new Transition(findState(tline[0]), tline[1], tline[2], findState(tline[3]), stack_push, id));
      id++;
    }

    apFile.close();
  }
}

void AP::checkData() {
  if(initial_state == NULL) {
    std::cout << "Estado inicial no forma parte del conjunto de estados";
    exit(EXIT_FAILURE);
  }

  if(!stack.check()) {
    std::cout << "Símbolo inicial de la pila no pertenece al alfabeto";
      exit(EXIT_FAILURE);
  }

  for(auto t : transitions) {
    if(t -> isNull()) {
      std::cout << "Transición " << t -> getId() << " incorrecta (estado no existe)";
      exit(EXIT_FAILURE);
    }
    if(!t -> checkAlphabet(E, stack.T)) {
      std::cout << "Transición " << t -> getId() << " incorrecta (elemento no pertenece al alfabeto)";
      exit(EXIT_FAILURE);
    }
  } 
}

std::vector<Transition*> AP::possibleMoves(State* now) {
  std::vector<Transition*> moves;
  for(auto t : transitions)
    if(t -> canTransitate(now, &stack, tape.substr(0, 1)))
      moves.push_back(t);
  return moves;
}

void AP::run(std::string cadena) {
  tape = cadena;
  std::string input;
  State* now = initial_state;
  std::vector<Transition*> moves;
  std::stack<ap_info*> apData;

  while(1) {
    apData.push(new ap_info(now, tape, &stack, possibleMoves(now)));
    
    std::cout << "---------------------------------------------------\n";
    std::cout << apData.top() -> now -> getId() << "\t" << apData.top() -> tape << "\t";
    apData.top() -> stack -> print();
    std::cout << "\t";
    for(auto m : apData.top() -> transitions) std::cout << m -> getId() << " ";
    std::cout << "\n";

    if(stack.empty() && tape.size() == 0) {  // mirar si esta bien puesto esto aqui
      std::cout << "Cadena pertenece al lenguaje.\n";
      break;
    }

    if(!apData.top() -> transitions.empty()) {
      transit(apData.top() -> transitions.front());
      apData.top() -> transitions.erase(apData.top() -> transitions.begin());
    } else { 
      while(apData.top() -> transitions.empty()) {
        apData.pop();
        std::cout << " uwu  ";
      }
    }
    if(apData.empty()) { // me quedo sin transiciones
      std::cout << "Cadena no pertenece al lenguaje.\n";
      break;
    }
  }
} 

State* AP::transit(Transition* transition) {
  stack.pop();
  if(transition -> consume()) 
    tape = tape.substr(1);
  stack.push(transition -> getPush());

  return transition -> getNext();
}



void AP::showInfo() {
  std::cout << "Estados: ";
  for(auto state : States) 
    std::cout << state -> getId() << " ";
    std::cout << "\n";

  std::cout << "Alfabeto de la entrada: ";
  E.print();

  std::cout << "Alfabeto de la pila: ";
  stack.T.print();

  std::cout << "Estado inicial: " << initial_state -> getId() << "\n";
  std::cout << "Símbolo inicial pila: " << stack.top() << "\n";

  std::cout << "Transiciones:\n";
  for(auto t : transitions)
    t -> print();
}