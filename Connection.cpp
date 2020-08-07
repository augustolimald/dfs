#include <iostream>
#include "Connection.hpp"

Connection::Connection(std::string subject, std::string requiredSubject, std::string type) {
  this->subject = subject;
  this->requiredSubject = requiredSubject;
  this->type = type;
}

std::string Connection::getSubject() {
  return subject;
}

std::string Connection::getRequiredSubject() {
  return requiredSubject;
}

std::string Connection::getType() {
  return type;
}
