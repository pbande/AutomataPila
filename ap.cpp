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
    stack.push(line);

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


/*void AP::run(std::string cadena) {


  while(!stack.empty())
} */


void AP::checkData() {
  if(initial_state == NULL) {
    std::cout << "Estado inicial no forma parte del conjunto de estados";
    exit(EXIT_FAILURE);
  }

  for(auto t : transitions)
    if(t -> isNull()) {
      std::cout << "Transición " << t -> getId() << " incorrecta";
      exit(EXIT_FAILURE);
    }
      
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