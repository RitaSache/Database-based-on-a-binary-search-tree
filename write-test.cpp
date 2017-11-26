// basic file operations
/*#include <iostream>
#include <fstream>
#include "Faculty.h"
using namespace std;

int main () {

  cout << "Creating Faculty" << endl;
  // Student *s = new Student(1, "plastic Bag", "junior", "math", 3.99, 2);
  Faculty *f = new Faculty(1, "Fart Bag", "Associate", "Math", 1);
  f->advisees[0] = 3;
  // f->advisees[1] = 4;

  cout << "Outputting file" << endl;

  ofstream outfile;
  outfile.open ("example.dat", ios::out | ios::binary);
  f->save(outfile);
  outfile.close();

  cout << "Reading file" << endl;

  Faculty g;
  ifstream infile;
  infile.open ("example.dat", ios::in | ios::binary);
  g.load(infile);
  infile.close();

  cout << "Printing faculty" << endl;

  cout << g.toString() << endl;

  return 0;
}*/