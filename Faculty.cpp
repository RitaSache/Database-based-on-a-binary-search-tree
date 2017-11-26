#include "Faculty.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

Faculty::Faculty(){};

Faculty::Faculty(int id, string Name, string Level, string Department, int arraySize){
	ID = id;
	name = Name;
	level = Level;
	department = Department;
	advisees = new int[arraySize];
	size = arraySize;
	for (int i = 0; i < size; i++) {
		advisees[i] = 0;
	}
}

Faculty::~Faculty(){
	delete[] advisees;
}

string Faculty::toString(){
	ostringstream ss;	
	ss 
	<< " Id is " << ID 
	<< ", name is " << name 
	<< ", level is " << level 
	<< ", department is " << department
	<< ", advisees are [";
	for(int i=0; i<size; i++){
		if(i == 0){
			ss << "" << advisees[i];
		}
		else{
			ss << ", " << advisees[i];
		}
	}
	ss << "]" << endl;
  	return ss.str();
}
Faculty* Faculty::copy(){
	Faculty* f = new Faculty(ID, name, level, department, size);
	for(int i = 0; i<size; i++){
		f->advisees[i] = advisees[i];
	}
	return f;
}

void Faculty::save(ofstream& output) {
	output.write(reinterpret_cast<const char*>(&ID), sizeof ID);

	int nameSize = name.size() + 1;
	output.write(reinterpret_cast<const char*>(&nameSize), sizeof nameSize);
	output.write(reinterpret_cast<const char*>(&name), nameSize);

	int levelSize = level.size() + 1;
	output.write(reinterpret_cast<const char*>(&levelSize), sizeof levelSize);
	output.write(reinterpret_cast<const char*>(&level), levelSize);

	int departmentSize = department.size() + 1;
	output.write(reinterpret_cast<const char*>(&departmentSize), sizeof departmentSize);
	output.write(reinterpret_cast<const char*>(&department), departmentSize);

	output.write(reinterpret_cast<const char*>(&size), sizeof size);
	for(int i = 0; i < size; i++) {
		int out = advisees[i];
		output.write(reinterpret_cast<const char*>(&out), sizeof out);
	}
}

void Faculty::load(ifstream& input) {
	input.read(reinterpret_cast<char*>(&ID), sizeof ID);

	int nameSize;
	input.read(reinterpret_cast<char*>(&nameSize), sizeof nameSize);
	input.read(reinterpret_cast<char*>(&name), nameSize);

	int levelSize;
	input.read(reinterpret_cast<char*>(&levelSize), sizeof levelSize);
	input.read(reinterpret_cast<char*>(&level), levelSize);

	int departmentSize;
	input.read(reinterpret_cast<char*>(&departmentSize), sizeof departmentSize);
	input.read(reinterpret_cast<char*>(&department), departmentSize);

	input.read(reinterpret_cast<char*>(&size), sizeof size);
	advisees = new int[size];
	for(int i = 0;i < size; i++) {
		int in = 0;
		input.read(reinterpret_cast<char*>(&in), sizeof in);
		advisees[i] = in;
	}
}


