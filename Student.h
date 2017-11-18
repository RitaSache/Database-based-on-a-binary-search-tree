#include <iostream>
using namespace std;

class Student{
	public:
		int ID;
		string name;
		string level;
		string major;
		double GPA;
		int advisor;
		Student(int id, string Name, string Level, string Major, double gpa, int Advisor);
		~Student();
		string toString();
};