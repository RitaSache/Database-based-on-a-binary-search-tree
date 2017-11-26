// basic file operations
#include <iostream>
#include <fstream>
#include "Faculty.h"
using namespace std;

int main () {

  // Student *s = new Student(1, "plastic Bag", "junior", "math", 3.99, 2);
  Faculty *f = new Faculty(1, "Fart Bag", "Associate", "Math", 2);
  f->advisees[0] = 3;
  f->advisees[1] = 4;

  ofstream outfile;
  outfile.open ("example.dat", ios::out | ios::binary);
  f->save(outfile);
  outfile.close();

  Faculty g;
  ifstream infile;
  infile.open ("example.dat", ios::in | ios::binary);
  g.load(infile);
  infile.close();

  cout << g.toString() << endl;

  return 0;
}