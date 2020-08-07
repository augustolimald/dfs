#include <iostream>
#include "Course.hpp"

class Graph {
  public:
    Graph(Course);

  private:
    char **matrix;
    int getSubjectIndex(std::string);
};