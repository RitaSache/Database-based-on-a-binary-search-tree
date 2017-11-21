#include <iostream>
using namespace std;

class Faculty{
	public:
		int ID;
		string name;
		string level;
		string department;
		int size;
		int *advisees;
		Faculty(int id, string Name, string Level, string Department, int arraySize);
		~Faculty();
		string toString();
		void fillAdvisees();
		bool duplicate(int id);
	};