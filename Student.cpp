#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

Student::Student(){}

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
Student* Student::copy(){
	Student* s = new Student(ID, name, level, major, GPA, advisor);
	return s;
}

void Student::save(ofstream& output) {
	output.write(reinterpret_cast<const char*>(&ID), sizeof ID);

	int nameSize = name.size() + 1;
	output.write(reinterpret_cast<const char*>(&nameSize), sizeof nameSize);
	output.write(reinterpret_cast<const char*>(&name), nameSize);

	int levelSize = level.size() + 1;
	output.write(reinterpret_cast<const char*>(&levelSize), sizeof levelSize);
	output.write(reinterpret_cast<const char*>(&level), levelSize);

	int majorSize = major.size() + 1;
	output.write(reinterpret_cast<const char*>(&majorSize), sizeof majorSize);
	output.write(reinterpret_cast<const char*>(&major), majorSize);

	output.write(reinterpret_cast<const char*>(&GPA), sizeof GPA);
	output.write(reinterpret_cast<const char*>(&advisor), sizeof advisor);
}

void Student::load(ifstream& input) {
	input.read(reinterpret_cast<char*>(&ID), sizeof ID);

	int nameSize;
	input.read(reinterpret_cast<char*>(&nameSize), sizeof nameSize);
	input.read(reinterpret_cast<char*>(&name), nameSize);

	int levelSize;
	input.read(reinterpret_cast<char*>(&levelSize), sizeof levelSize);
	input.read(reinterpret_cast<char*>(&level), levelSize);

	int majorSize;
	input.read(reinterpret_cast<char*>(&majorSize), sizeof majorSize);
	input.read(reinterpret_cast<char*>(&major), majorSize);

	input.read(reinterpret_cast<char*>(&GPA), sizeof GPA);
	input.read(reinterpret_cast<char*>(&advisor), sizeof advisor);
}

