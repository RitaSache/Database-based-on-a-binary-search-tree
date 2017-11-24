#include "Faculty.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

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

Faculty::~Faculty(){}

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

/*void Faculty::fillAdvisees(){
	int id = 0;
	for(int i = 0; i < size; i++){
		cout << "Please provide an advisee's ID" << endl;
		cin >> id;

		if(id == 0) {
			cout << "Id cannot be equal to 0" << endl;
			i--;
			continue;
		}
		if(duplicate(id)) {
			cout << "This id already exists" << endl;
			i--;
			continue;
		}

		advisees[i] = id;
	}
}

bool Faculty::duplicate(int id){
	// duplicate 1?
	// 1,2,3
	// 2,2,2
	// 2,1,3

	for(int i = 0; i < size; i++){
		if(id == advisees[i]){
			return true;
		}
	}
	return false;
}
*/
