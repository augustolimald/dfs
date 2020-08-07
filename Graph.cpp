#include <iostream>
#include "Graph.hpp"

using namespace std;

int alphabet_length = 36;
char alphabet[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','0','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

int getLetter(string str) {
  char letter = str.at(0);
  for (int i = 0; i < alphabet_length; i++) {
    if (letter == alphabet[i]) return i + 1;
  }
  return -1;
}

int lexOrder(string str) {
  if (str.size() == 0) return 0;
  if (str.size() == 1) return getLetter(str);

  string a = str.substr(0, 1);
  string u = str.substr(1);

  return (getLetter(a) * alphabet_length ^ u.size()) + (lexOrder(u));
}

Graph::Graph(Course course) {
  int size = lexOrder("GGG333");
  
  matrix = new char*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new char[size];
    for (int j = 0; j < size; j++) {
      matrix[i][j] = '-';
    }
  }

  for(int i = 0; i < course.getTotalOfConnections(); i++) {
    Connection c = course.getConnection(i);
    int x = getSubjectIndex(c.getSubject());
    int y = getSubjectIndex(c.getRequiredSubject());
    matrix[x][y] = c.getType().at(0);
  }
}

int Graph::getSubjectIndex(std::string subject) {
  return lexOrder(subject);
}