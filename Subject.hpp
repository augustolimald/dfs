#include <iostream>

class Subject {
  public:
    Subject(std::string, std::string, std::string);
    std::string getCode();
    std::string getName();
    std::string getType();

  private:
    std::string code, type, name;
};
