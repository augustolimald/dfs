#include <iostream>
#include "Course.hpp"

class Graph {
  public:
    Graph(Course*);
    ~Graph();
    void showThree();

  private:
    Course *course;
    char **matrix;
    int size;

    int getSubjectIndex(std::string);
    void dfs(int, bool *, int);
};