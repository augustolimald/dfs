#include <iostream>

class Connection {
  public:
    Connection(std::string, std::string, std::string);
    std::string getSubject();
    std::string getRequiredSubject();
    std::string getType();

  private:
    std::string subject, requiredSubject, type;
};
