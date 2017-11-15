#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int id, string Name, string Level, string Major, double gpa, int Advisor){
	ID = id;
	name = Name;
	level = Level;
	major = Major;
	GPA = gpa;
	advisor = Advisor;	
}

Student::~Student(){}