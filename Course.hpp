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
    
    /**
     * Methods to deal with subjects
     */
    void addSubject(Subject);
    Subject getSubject(int);
    int getTotalOfSubjects();

    /**
     * Methods to deal with connections
     */
    void addConnection(Connection);
    Connection getConnection(int);
    int getTotalOfConnections();

  private:
    std::string code, type, name;
    std::vector<Subject> subjects;
    std::vector<Connection> connections;
};
