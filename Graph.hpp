#include <iostream>
#include "Course.hpp"

class Graph {
  public:
    /**
     * Constructor and Destructor
     */
    Graph(Course*);
    ~Graph();

    /**
     * Public methods
     */
    void showThree();
    void showSubject(std::string);
    void showCriticalSubjects();

  private:
    /**
     * Data Structures 
     */
    Course *course;
    char **matrix;
    int size;

    /**
     * Returns the index of a subject
     */
    int getSubjectIndex(std::string);

    /**
     * Runs a Depth-First Algorithm
     */
    void dfs(int, bool*, int, int&, bool);

    /**
     * Runs a Depth-First Algorithm in a reverse direction
     */
    void reverse_dfs(int, bool*, int&);
};