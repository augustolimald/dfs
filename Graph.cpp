#include <iostream>
#include "Graph.hpp"

using namespace std;

Graph::Graph(Course *course) {
  this->course = course;
  this->size = course->getTotalOfSubjects();
  
  matrix = new char*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new char[size];
    for (int j = 0; j < size; j++) {
      matrix[i][j] = '-';
    }
  }

  for(int i = 0; i < course->getTotalOfConnections(); i++) {
    Connection c = course->getConnection(i);
    int x = getSubjectIndex(c.getSubject());
    int y = getSubjectIndex(c.getRequiredSubject());
    matrix[x][y] = c.getType().at(0);
  }
}

Graph::~Graph() {
  for (int i = 0; i < size; i++)
    delete matrix[i];
  delete[] matrix;
}

int Graph::getSubjectIndex(std::string subject) {
  for (int i = 0; i < size; i++) {
    if (course->getSubject(i).getCode() == subject) {
      return i;
    }
  }

  return -1;
}

void Graph::dfs(int index, bool *visited, int level) {
  cout << string(level * 2, ' ') << course->getSubject(index).getName() << endl;
  visited[index] = true;

  for (int i = 0; i < size; i++) {
    if (matrix[index][i] != '-') {
      if (!visited[i])
        dfs(i, visited, level + 1);
    }
  }
}

void Graph::showThree() {
  for (int i = 0; i < size; i++) {
    bool *visited = new bool[size];
		for (int i = 0; i < size; i++)
			visited[i] = false;
    dfs(i, visited, 0);
    delete visited;
  }
}