#include <iostream>
#include <fstream>
#include "Graph.hpp"

using namespace std;

void clean();
Course* loadData(string);
int readMenuOption(Course*);

/**
 * Main method
 */
int main() {
  // Load data
  Course *course = loadData("data.txt");
  Graph *graph = new Graph(course);
  
  // Stay in loop until user closes the application
  int option;
  do {
    option = readMenuOption(course);
    clean();

    switch (option) {
      case 1: {
        cout << "Informe o código da disciplina: ";
        string subject;
        cin >> subject;
        graph->showSubject(subject);
        break;
      }
      
      case 2: {
        graph->showCriticalSubjects();
        break;
      }

      case 3: {
        graph->showTree();
        break;
      }
    }
  } while(option != 4);

  cout << "Obrigado por usar nossos serviços! Volte sempre..." << endl;

  // Clean memory and close
  delete graph;
  delete course;
  return 0;
}

/**
 * Method to clean the screen
 */
void clean() {
  for(int i = 0; i < 50; i++)
    cout << endl;
}

/**
 * Method to load data from file and load in a course object
 */
Course* loadData(string filename) {
  ifstream file(filename);
  int amount;
  string a, b, c;

  // Course Data
  file >> a;
  file >> b;
  getline(file, c);
  c = c.substr(1);
  Course *course = new Course(a, b, c);

  // Subjects Data
  file >> amount;
  for(int i = 0; i < amount; i++) {
    file >> a;
    file >> b;
    getline(file, c);
    c = c.substr(1);

    Subject subject(a, b, c);
    course->addSubject(subject);
  }

  // Connections Data
  file >> amount;
  for(int i = 0; i < amount; i++) {
    file >> a;
    file >> b;
    file >> c;

    Connection connection(a, b, c);
    course->addConnection(connection);
  }

  file.close();
  return course;
}

/**
 * Method to show the options menu and read user's option
 */
int readMenuOption(Course *course) {
  cout << endl
       << endl
       << endl
       << course->getCode() 
       << " - " 
       << course->getName() 
       << " (" 
       << course->getType() 
       << ")" 
       << endl
       << "MENU DE OPÇÕES"
       << endl
       << "1 - Visualizar requisitos de uma disciplina"
       << endl
       << "2 - Visualizar disciplinas críticas"
       << endl
       << "3 - Visualizar todas as disciplinas de forma hieráquica"
       << endl
       << "4 - Sair"
       << endl
       << "Informe sua opção: ";
  
  int option;
  cin >> option;

  if (option < 1 || option > 4) {
    cout << "Não foi possível entender sua opção, vamos tentar novamente..." << endl;
    return readMenuOption(course);
  }

  return option;
}
