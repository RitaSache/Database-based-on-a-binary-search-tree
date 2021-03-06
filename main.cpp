#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <iostream>
#include "GenStack.h"
#include <fstream>
using namespace std;

void changeAdvisor(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int studentId=0; 
	int facultyId=0;
	cout << "Please provide a student's ID " << endl;
	cin >> studentId;
	cout << "Please provide an advisor's ID " << endl;
	cin >> facultyId;
	if(facultyTree -> get(facultyId) != NULL && studentTree -> get(studentId) != NULL){
		Student *s = studentTree -> get(studentId);
		s -> advisor = facultyId;
	}
	else{
		cout << "No faculty or student found" << endl;
	}
}
void setToZero(Faculty *f, int id){
	for(int i = 0; i < f->size; i++){
		if(f->advisees[i] == id){
			f->advisees[i] = 0;
		}
	}
}
void removeAdvisee(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int adviseeId=0;
	int facultyId=0;
	cout << "Please provide an advisee's ID " << endl;
	cin >> adviseeId;
	cout << "Please provide a faculty's ID " << endl;
	cin >> facultyId;
	if(facultyTree -> get(facultyId) != NULL && studentTree -> get(adviseeId) != NULL){
		Faculty *f = facultyTree -> get(facultyId);
		setToZero(f, adviseeId);
	}
	else {
		cout << "No faculty or student found" << endl;
	}
}
void displayStudent(BST<Student>* studentTree){
	int studentId = 0;
	cout << "Please provide a student's ID " << endl;
	cin >> studentId;
	Student *s = studentTree -> get(studentId);
	if (s == NULL){
		cout << "no student found " << endl;
	}
	else {
		cout << s -> toString() << endl;
	}
}
void displayFaculty(BST<Faculty>* facultyTree){
	int facultyId = 0;
	cout << "Please provide a faculty's ID " << endl;
	cin >> facultyId;
	Faculty *f = facultyTree -> get(facultyId);
	if(f == NULL){
		cout << "no faculty found" << endl;
	}
	else {
		cout << f -> toString() << endl;
	}
}
void printAdvisor(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int studentId = 0;
	cout << "Please provide a student's ID" << endl;
	cin >> studentId;
	Student *s = studentTree -> get(studentId);
	Faculty *f = facultyTree -> get(s -> advisor);
	if (f == NULL){
		cout << "no faculty found" << endl;
	}	
	else{
		cout << f -> toString() << endl;
	}
}
void printAdvisees(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int facultyId = 0;
	cout << "Please provide a faculty's ID " << endl;
	cin >> facultyId;
	Faculty *f = facultyTree -> get(facultyId);
	if(f != NULL){
		for(int i = 0; i < f->size; i++){
			if(f->advisees[i] != 0) {
				cout << studentTree -> get(f -> advisees[i]) -> toString() << endl;
			}
			else{
				cout << "No advisees to print" << endl;
			}
		}
	}
	else {
		cout << "no faculty found" << endl;
	}
}
int chooseStudentId(BST<Student>* studentTree){
	int studentId = rand();
	if(studentTree->contains(studentId)){
		return chooseStudentId(studentTree);
	}
	else{
		return studentId;
	}
}
int chooseFacultyId(BST<Faculty>* facultyTree){
	int facultyId = rand();
	if(facultyTree->contains(facultyId)){
		return chooseFacultyId(facultyTree);
	}
	else{
		return facultyId;
	}
}
void addStudent(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	string studentName;
	string studentLevel;
	string studentMajor;
	double studentGpa = 0.00;
	int studentAdvisor = 0;
	cout << "Please provide a student's name " << endl;
	cin >> studentName;
	cout << "Please provide a student's level " << endl;
	cin >> studentLevel;
	cout << "Please provide a student's major " << endl;
	cin >> studentMajor;
	cout << "Please provide a student's GPA in this format 0.00 " << endl;//fix double
	cin >> studentGpa;
	if(!facultyTree -> isEmpty()) {
		while(true) {
		cout << "Please provide a student advisor's ID " << endl;
		cin >> studentAdvisor;
			if (!facultyTree -> contains(studentAdvisor)){
				cout << "There is no advisor with the given ID " << endl;
				continue;
			}
			else{
				break;
			}
		}
	}
	else{
		cout << "Cannot add an advisor because there are no faculty in the database. " << endl;
	}
	Student *student = new Student(chooseStudentId(studentTree), studentName, studentLevel, studentMajor, studentGpa, studentAdvisor);
	studentTree->insert(student->ID, student);
}
void deleteStudent(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int studentId = 0;
	cout << "Please provide a student's id " << endl;
	cin >> studentId;
	if(studentTree -> contains(studentId)){
		Student *s = studentTree -> get(studentId);
		Faculty *f = facultyTree -> get(s->advisor);
		setToZero(f, studentId);
		studentTree->deleteNode(studentId);
	}
	else{
		cout << "No student found with the given ID " << endl;
	}
}
bool duplicate(int id, Faculty *f){
	for(int i = 0; i < f->size; i++){
		if(id == f->advisees[i]){
			return true;
		}
	}
	return false;
}
void fillAdvisees(BST<Student>* studentTree, Faculty *f){
	int id = 0;
	if(!studentTree->isEmpty()){
		for(int i = 0; i < f->size; i++){
			cout << "Please provide an advisee's ID" << endl;
			cin >> id;

			if(duplicate(id, f)) {
				cout << "This id already exists" << endl;
				i--;
				continue;
			}
			if(studentTree->contains(id)) {
				f->advisees[i] = id;
			}
			else {
				cout << "this student ID is not in the database " << endl;
				i--;
				continue;
			}	
		}
	}
	else{
		cout << "Cannot assign advisees, there are no students in the database yet. Add a student first. " << endl;
	}
}

void addFaculty(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	string facultyName;
	string facultyLevel;
	string facultyDepartment;
	int numberOfAdvisees = 0;
	cout << "Please provide a faculty's name " << endl;
	cin >> facultyName;
	cout << "Please provide a faculty's level " << endl;
	cin >> facultyLevel;
	cout << "Please provide a faculty's department " << endl;
	cin >> facultyDepartment;
	while (!studentTree -> isEmpty()){
		cout << "Please provide a number of advisees " << endl;
		cin >> numberOfAdvisees;
		if(numberOfAdvisees > studentTree->count){
			cout << "number of advisees exceeds the number of students available in the database " << endl;
			continue;
		}
		else {
			break;
		}
	}
	Faculty *faculty = new Faculty(chooseFacultyId(facultyTree), facultyName, facultyLevel, facultyDepartment, numberOfAdvisees);
	facultyTree->insert(faculty->ID, faculty);
	fillAdvisees(studentTree, faculty);
}
void deleteFaculty(BST<Student>* studentTree, BST<Faculty>* facultyTree){
	int facultyId = 0;
	cout << "Please provide a faculty's id " << endl;
	cin >> facultyId; 
	if(facultyTree->contains(facultyId)) {
		Faculty *f = facultyTree -> get(facultyId);
		for(int i = 0; i < f->size; i++){
			if(f->advisees[i]!=0){
				Student *s = studentTree -> get(f -> advisees[i]);
				s -> advisor = 0;
			}
		}
		facultyTree->deleteNode(facultyId);
	}
	else {
		cout << "faculty with this ID was not found" << endl;
	}
}
void writeToFile(BST<Student>* studentTree, BST<Faculty>* facultyTree){
  ofstream outfile;
  outfile.open ("StudentTable", ios::out | ios::binary);
  outfile.write(reinterpret_cast<const char*>(&(studentTree->count)), sizeof studentTree->count);
  studentTree->save(outfile, studentTree->root);
  outfile.close();

  outfile.open ("FacultyTable", ios::out | ios::binary);
  outfile.write(reinterpret_cast<const char*>(&(facultyTree->count)), sizeof facultyTree->count);
  facultyTree->save(outfile, facultyTree->root);
  outfile.close();
}
void readFromFile(BST<Student>* studentTree, BST<Faculty>* facultyTree){
  ifstream infile;
  infile.open ("StudentTable", ios::in | ios::binary);
  if (infile.good()) {
  	cout << "Loading Student" << endl;
  	studentTree->load(infile);	
  }
  infile.close();

  infile.open ("FacultyTable", ios::in | ios::binary);
  if (infile.good()) {
  	cout << "Loading Faculty" << endl;
  	facultyTree->load(infile);
  }
  infile.close();
}
//main presents menu to the user and depending on a chosen option lets the user manipulate the database
int main() {
	BST<Student>* masterStudent = new BST <Student>();
	BST<Faculty>* masterFaculty = new BST <Faculty>();
	GenStack<BST<Student> *> studentTrees(5);
	GenStack<BST<Faculty> *> facultyTrees(5);
	readFromFile(masterStudent, masterFaculty);
	while(true){
	int response;
	cout << "Choose a number from the menu: " << endl;
	cout << "1.  Print all students and their information (sorted by ascending id #)" << endl;
	cout << "2.  Print all faculty and their information (sorted by ascending id #)" << endl;
	cout << "3.  Find and display student information given the students id" << endl;
	cout << "4.  Find and display faculty information given the faculty id" << endl;
	cout << "5.  Given a student’s id, print the name and info of their faculty advisor" << endl;
	cout << "6.  Given a faculty id, print all the names and info of his/her advisees" << endl;
	cout << "7.  Add a new student" << endl;
	cout << "8.  Delete a student given the id" << endl;
	cout << "9.  Add a new faculty member" << endl;
	cout << "10. Delete a faculty member given the id" << endl;
	cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
	cout << "12. Remove an advisee from a faculty member given the ids" << endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit" << endl;
	cin >> response;

	if(response == 1){
		masterStudent->printTree(masterStudent->root);
	}
	else if(response == 2){
		masterFaculty->printTree(masterFaculty->root);
	}
	else if(response == 3){
		displayStudent(masterStudent);
	}
	else if(response == 4){
		displayFaculty(masterFaculty);
	}
	else if(response == 5){
		printAdvisor(masterStudent, masterFaculty);
	}
	else if(response == 6){
		printAdvisees(masterStudent, masterFaculty);
	}
	else if(response == 7){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		addStudent(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;
	}
	else if(response == 8){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		deleteStudent(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;
	}
	else if(response == 9){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		addFaculty(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;
	}
	else if(response == 10){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		deleteFaculty(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;
	
	}
	else if(response == 11){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		changeAdvisor(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;
	}
	else if(response == 12){
		BST<Student> *newMasterStudent = masterStudent->copy();
		BST<Faculty> *newMasterFaculty = masterFaculty->copy();

		studentTrees.push(masterStudent);
		facultyTrees.push(masterFaculty);
		removeAdvisee(newMasterStudent, newMasterFaculty);

		masterStudent = newMasterStudent;
		masterFaculty = newMasterFaculty;	
	}
	else if(response == 13){
		masterStudent = studentTrees.pop();
		masterFaculty = facultyTrees.pop();
	}
	else if(response == 14){
		break;
	}
	else{
		cout << "Input was not valid" << endl;
	}
	}
	writeToFile(masterStudent, masterFaculty);
	return 0;
}
//create a person class with member vars that overlap with student and faculty. then create student and faculty sublasses that inherit from the person class
//6 classes: BST, Faculty tree, student tree, Person, faculty and student subclasses
//ascending order is a in order traversal
//5 and 6 bullet points can call the method from 3 and 4
//when adding a student, do not prompt for ID, have a random number chosen from some amount. do not increment ID by 1 with a tree because it'll get skewed. distribute IDs evenly and make sure not to duplicate id, check if id already exists.
//when deleting a faculty have to reassign all their advisees to another facutly, promt the user to enter an id of another faculty to assign to or just randomly pick another faculty to assign advisees to
//if cannot be rassigned, say you cannot fire that faculty or make a new one
//for 11 promt for id and make sure that id exists and then assign
//13. rollback, means undo. use a stack to implement this. for last 5 commands
//make a method add to stack, every time you change smth in DB, call add to stack method. empty stack when exiting the progran
//

