#include "Faculty.h"
#include <iostream>
#include <string>

using namespace std;

Faculty::Faculty(int id, string Name, string Level, string Department){
	ID = id;
	name = Name;
	level = Level;
	department = Department;
}

Faculty::~Faculty(){}

string Faculty::toString(){
	string r =  "id is " + to_string(ID) + ", name is " + name + ", level is " + level + ", department is " + department;
	return r;
}