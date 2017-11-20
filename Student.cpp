#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>
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
	ostringstream ss;
  	ss << " Id is " << ID << ", name is " << name << ", level is " << level << ", major is " << major << ", gpa is " << GPA << ", advisor is " << advisor << endl;
  	return ss.str();
}