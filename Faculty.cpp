#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty(int id, string Name, string Level, string Department){
	ID = id;
	name = Name;
	level = Level;
	department = Department;
}

Faculty::~Faculty(){}