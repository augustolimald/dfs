#include <iostream>
#include <fstream>
#include "Graph.hpp"

using namespace std;

Course loadData(string);

int main() {
  Course course = loadData("data.txt");
  Graph graph(course);
  return 0;
}

Course loadData(string filename) {
  ifstream file(filename);
  int amount;
  string a, b, c;

  /**
   * Course Data
   */
  file >> a;
  file >> b;
  getline(file, c);
  c = c.substr(1);
  Course course(a, b, c);

  /**
   * Subjects Data
   */
  file >> amount;
  for(int i = 0; i < amount; i++) {
    file >> a;
    file >> b;
    getline(file, c);
    c = c.substr(1);

    Subject subject(a, b, c);
    course.addSubject(subject);
  }

  /**
   * Connections Data
   */
  file >> amount;
  for(int i = 0; i < amount; i++) {
    file >> a;
    file >> b;
    file >> c;

    Connection connection(a, b, c);
    course.addConnection(connection);
  }

  file.close();
  return course;
}