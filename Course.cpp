#include <iostream>
#include <vector>
#include "Course.hpp"

Course::Course(std::string code, std::string type, std::string name) {
  this->code = code;
  this->type = type;
  this->name = name;
}

std::string Course::getCode() {
  return code;
}

std::string Course::getName() {
  return name;
}

std::string Course::getType() {
  return type;
}

void Course::addSubject(Subject subject) {
  subjects.push_back(subject);
}

Subject Course::getSubject(int index) {
  return subjects.at(index);
}

int Course::getTotalOfSubjects() {
  return subjects.size();
}

void Course::addConnection(Connection connection) {
  connections.push_back(connection);
}

Connection Course::getConnection(int index) {
  return connections.at(index);
}

int Course::getTotalOfConnections() {
  return connections.size();
}