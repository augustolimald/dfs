#include <vector>
#include <algorithm>
#include <iostream>
#include "Graph.hpp"

using namespace std;

/**
 * Auxiliar structure to list critical subjects
 */
struct CriticalSubject {
  string name;
  int amount;
};

bool criticalSubjectSorter(CriticalSubject const& cs1, CriticalSubject const& cs2) {
  return cs1.amount > cs2.amount;
}

/**
 * Graph Class Implementation
 */
Graph::Graph(Course *course) {
  this->course = course;
  this->size = course->getTotalOfSubjects();
  
  // Init matrix structure
  matrix = new char*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new char[size];
    for (int j = 0; j < size; j++) {
      matrix[i][j] = '-';
    }
  }

  // Fill each position in the matrix
  for(int i = 0; i < course->getTotalOfConnections(); i++) {
    Connection c = course->getConnection(i);
    int x = getSubjectIndex(c.getSubject());
    int y = getSubjectIndex(c.getRequiredSubject());
    matrix[x][y] = c.getType().at(0);
  }
}

Graph::~Graph() {
  for (int i = 0; i < size; i++)
    delete[] matrix[i];
  delete[] matrix;
}

int Graph::getSubjectIndex(std::string subject) {
  // Walks in array to find the subject
  for (int i = 0; i < size; i++) {
    if (course->getSubject(i).getCode() == subject) {
      return i;
    }
  }

  return -1;
}

void Graph::reverse_dfs(int index, bool *visited, int &amount) {
  // Mark vertice as visited
  visited[index] = true;
  amount++;

  // Call DFS method to each unvisited neighbor
  for (int i = 0; i < size; i++) {
    if (matrix[i][index] != '-') {
      if (!visited[i])
        reverse_dfs(i, visited, amount);
    }
  }
}

void Graph::dfs(int index, bool *visited, int level, bool show) {
  // Mark vertice as visited
  visited[index] = true;
  
  // Show in the output
  if (show) {
    cout << string(level * 2, ' ') << course->getSubject(index).getName() << endl;
  }

  // Call DFS method to each unvisited neighbor
  for (int i = 0; i < size; i++) {
    if (matrix[index][i] != '-') {
      if (!visited[i])
        dfs(i, visited, level + 1, show);
    }
  }
}

void Graph::showThree() {
  // Call DFS to each vertice
  for (int i = 0; i < size; i++) {
    // Init auxiliar structure
    bool *visited = new bool[size];
		for (int j = 0; j < size; j++)
			visited[j] = false;
    
    // Call DFS
    dfs(i, visited, 0, true);
    delete[] visited;
  }
}

void Graph::showSubject(string subject) {
  // Find the subject index
  int index = getSubjectIndex(subject);
  if (index == -1) {
    cout << "Disciplina não encontrada" << endl;
    return;
  }

  // Init auxiliar structure
  bool *visited = new bool[size];
	for (int i = 0; i < size; i++)
	  visited[i] = false;
    
  // Call DFS
  dfs(index, visited, 0, true);
  delete[] visited;
}

void Graph::showCriticalSubjects() {
  vector<CriticalSubject> subjects;

  // Call Reverse DFS to each vertice
  for (int i = 0; i < size; i++) {
    // Init auxiliar structure
    bool *visited = new bool[size];
    for (int j = 0; j < size; j++)
      visited[j] = false;
    
    // Call Reverse DFS
    int amount = -1;
    reverse_dfs(i, visited, amount);
    
    // Add to vector
    CriticalSubject cs;
    cs.name = course->getSubject(i).getName();
    cs.amount = amount;
    subjects.push_back(cs);

    delete[] visited;
  }

  // Sort the subjects
  std::sort(subjects.begin(), subjects.end(), &criticalSubjectSorter);

  // Show the first 5 subjects
  cout << "Disciplinas Críticas" << endl;
  for (int i = 0; i < 5; i++) {
    cout << subjects.at(i).amount << " - " << subjects.at(i).name << endl;
  }
}