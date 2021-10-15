#include "ap_info.h"

Ap_info::Ap_info(State* now_, std::string tape_, Stack stack_, std::vector<Transition*> t_) {
    now = now_;
    tape = tape_;
    stack = stack_;
    transitions = t_;
}