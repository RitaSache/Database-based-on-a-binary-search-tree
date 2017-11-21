#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <iostream>
using namespace std;

int main() {

	BST<Student>* masterStudent = new BST <Student>();
	Student *clam = new Student(2, "Clam", "Junior", "Business", 3.3, 1);
	masterStudent->insert(clam->ID, clam);
	masterStudent->printTree(masterStudent->root);


	BST<Faculty>* masterFaculty = new BST <Faculty>();
	Faculty *b = new Faculty(1, "Boring", "Associate", "Math", 2);
	masterFaculty->insert(b->ID, b);
	masterFaculty->printTree(masterFaculty->root);
	b -> fillAdvisees();

	Faculty *f = masterFaculty -> get(b->ID);
	if (f == NULL) {
		cout << "No faculty found";
	} else {
		cout << clam -> toString();
	}

	if (clam->advisor != 0) {
		Faculty *f = masterFaculty -> get(clam->advisor);
		if (f == NULL) {
			cout << "No faculty found";
		} else {
			cout << f -> toString();
		}
	}

	masterStudent -> deleteNode(2);
	cout << "printing tree";
	masterStudent->printTree(masterStudent->root);

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

