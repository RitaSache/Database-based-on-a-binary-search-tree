// basic file operations
/*#include <iostream>
#include <fstream>
using namespace std;

int main () {

  int x = 5;

  ofstream myfile;
  myfile.open ("example.dat", ios::out | ios::binary);
  myfile.write(reinterpret_cast<const char*>(&x), sizeof x);
  myfile.close();

  int p;

  ifstream infile;
  infile.open("example.dat", ios::out | ios::binary);
  infile.read(reinterpret_cast<char*>(&p), sizeof p);
  infile.close();

  cout << p << endl;

  return 0;
}*/