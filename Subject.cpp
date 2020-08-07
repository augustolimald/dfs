#include <iostream>
#include "Subject.hpp"

Subject::Subject(std::string code, std::string type, std::string name) {
  this->code = code;
  this->type = type;
  this->name = name;
}

std::string Subject::getCode() {
  return code;
}

std::string Subject::getName() {
  return name;
}

std::string Subject::getType() {
  return type;
}