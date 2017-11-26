// basic file operations
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

int main () {

  Student *s = new Student(1, "plastic Bag", "junior", "math", 3.99, 2);
  ofstream outfile;
  outfile.open ("example.dat", ios::out | ios::binary);
  s->save(outfile);
  outfile.close();

  Student p;
  ifstream infile;
  infile.open ("example.dat", ios::in | ios::binary);
  p.load(infile);
  infile.close();

  cout << p.toString() << endl;

  return 0;
}