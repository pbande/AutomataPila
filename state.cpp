#include "state.h"

State::State() {

}

State::State(std::string id_, bool final_ = false) {
  id = id_;
  final = final_;
}

State::~State() {

}

void State::setFinal() {
  final = true;
}

bool State::isFinal() {
  return final;
}

std::string State::getId() {
  return id;
}