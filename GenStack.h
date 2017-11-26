#include <iostream>

using namespace std;
template <class T>
class GenStack {
	public:
		GenStack(int maxSize);
		~GenStack();

		//replacing char data with T data
		void push(T data); //T to make it a template data type. This T will be replaced with the type you pass when you instantiat a stack.
		T pop();
		T peek();
		int isFull();
		int isEmpty();

		int top; //index top to keep track of the top element in stack
		int max;
		T *myArray;
		 //pointer that will act as a back in array, stack of chars. not initiallized, can be changed dynamically
		
};
//constructor for GenStack that creates a dynamic array and fills it up with zeros
template <class T>
GenStack<T>::GenStack(int maxSize){
	myArray = new T[maxSize];
	for(int i=0; i<maxSize; i++){
		myArray[i]=NULL;
	}
	max = maxSize;
	top = -1;
}
//deconstructor for GenStack that deletes objects
template <class T>
GenStack<T>::~GenStack() {
	delete [] myArray; 
}
//push method that checks whether an array is full and adds to the stack accordingly. if full, automatically allocates more space for itself
template <class T>
void GenStack<T>::push(T data) {
	if (!isFull()) {
		myArray[++top] = data;
	}
	else {
		for(int i = 1; i < max; i++){
    		myArray[i-1] = myArray[i];
    	}
		myArray[top] = data;
	}

}
//pop method that checks if an array is empty and pops accordingly
template <class T>
T GenStack<T>::pop(){
	if(!isEmpty()){
		return myArray[top--];
	}
	else {
		return NULL;
	}
}
//peek method that checks whether an array is empty and if not it returns the top element in the stack
template <class T>
T GenStack<T>::peek(){
	if (!isEmpty()) {
		return myArray[top];
	}
	else {
		return NULL;
	}
}
//checks whether the stack is full
template <class T>
int GenStack<T>::isFull(){
	return (top == max - 1);
}
//checks whether the stack is empty
template <class T>
int GenStack<T>::isEmpty(){
	return (top == -1);
}