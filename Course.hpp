#include <iostream>
#include <vector>
#include "Subject.hpp"
#include "Connection.hpp"

class Course {
  public:
    Course(std::string, std::string, std::string);
    std::string getCode();
    std::string getName();
    std::string getType();
    
    void addSubject(Subject);
    Subject getSubject(int);
    int getTotalOfSubjects();

    void addConnection(Connection);
    Connection getConnection(int);
    int getTotalOfConnections();

  private:
    std::string code, type, name;
    std::vector<Subject> subjects;
    std::vector<Connection> connections;
};
