#include "Student.h"
#include <iostream>
#include <string>
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

string Student::toString(){
	string r = "id is " + to_string(ID) + ", name is " + name + ", level is " + level + ", major is " + major + ", gpa is " + to_string(GPA) + ", advisor is "+ to_string(advisor);
	return r;
}