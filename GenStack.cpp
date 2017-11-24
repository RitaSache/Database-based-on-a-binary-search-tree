/*#include <iostream>
#include "GenStack.h"
using namespace std;

GenStack::GenStack(int maxSize){
	myArray = new BST<T>[maxSize];
	fill_n(myArray, maxSize, 0);
	max = maxSize;
	top = -1;
}
//deconstructor for GenStack that deletes objects

GenStack::~GenStack() {
	cout << "object deleted" << endl;
	delete [] myArray; 
	delete [] biggerArray;
}
//push method that checks whether an array is full and adds to the stack accordingly. if full, automatically allocates more space for itself
void GenStack::push(BST<T> data) {
	if (!isFull()) {
		myArray[++top] = data;
	}
	else {
		max = max*2;
		biggerArray = new BST<T>[max];
		fill_n(biggerArray, max, 0);
		top = -1;
		myArray = biggerArray;
	}

}
//pop method that checks if an array is empty and pops accordingly
BST<T> GenStack::pop(){
	if(!isEmpty()){
		return myArray[top--];
	}
	else {
		return '\0';
	}
}
//peek method that checks whether an array is empty and if not it returns the top element in the stack
BST<T> GenStack::peek(){
	if (!isEmpty()) {
		return myArray[top];
	}
	else {
		return '\0';
	}
}
//checks whether the stack is full
int GenStack::isFull(){
	return (top == max - 1);
}
//checks whether the stack is empty
int GenStack::isEmpty(){
	return (top == -1);
}
*/