#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <iostream>
#include <algorithm>
using namespace std;

void changeAdvisor(BST<Student>* studentTree, BST<Faculty>* facultyTree, int studentId, int facultyId){
	if(facultyTree -> get(facultyId) != NULL && studentTree -> get(studentId) != NULL){
		Student *s = studentTree -> get(studentId);
		s -> advisor = facultyId;
	}
	else{
		cout << "No faculty or student found" << endl;
	}
}
void removeAdvisee(BST<Student>* studentTree, BST<Faculty>* facultyTree, int adviseeId, int facultyId){
	if(facultyTree -> get(facultyId) != NULL && studentTree -> get(adviseeId) != NULL){
		Faculty *f = facultyTree -> get(facultyId);
		remove(f -> advisees, f -> advisees + f -> size, adviseeId);
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

int main() {
	BST<Student>* masterStudent = new BST <Student>();
	BST<Faculty>* masterFaculty = new BST <Faculty>();

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

	}
	/*BST<Student>* masterStudent = new BST <Student>();
	Student *clam = new Student(2, "Clam", "Junior", "Business", 3.3, 1);
	masterStudent->insert(clam->ID, clam);*/
	// masterStudent->printTree(masterStudent->root);


	/*BST<Faculty>* masterFaculty = new BST <Faculty>();
	Faculty *b = new Faculty(1, "Boring", "Associate", "Math", 2);
	masterFaculty->insert(b->ID, b);
	b -> fillAdvisees();*/
	// masterFaculty->printTree(masterFaculty->root);

	// Faculty *f = masterFaculty -> get(b->ID);
	// if (f == NULL) {
	// 	cout << "No faculty found";
	// } else {
	// 	cout << clam -> toString();
	// }

	// if (clam->advisor != 0) {
	// 	Faculty *f = masterFaculty -> get(clam->advisor);
	// 	if (f == NULL) {
	// 		cout << "No faculty found";
	// 	} else {
	// 		cout << f -> toString();
	// 	}
	// }

	// changeAdvisor(masterStudent, masterFaculty, clam->ID, 7);
	// masterStudent->printTree(masterStudent->root);
	// removeAdvisee(masterStudent, masterFaculty, 3, b-> ID);
	//masterFaculty->printTree(masterFaculty->root);


	/*masterStudent -> deleteNode(2);
	cout << "printing tree";
	masterStudent->printTree(masterStudent->root);*/



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

