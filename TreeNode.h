
#include <iostream>
using namespace std;
template <class T>
class TreeNode {
	public:
		TreeNode();
		TreeNode(int key); //overloaded constructor, key 
		//here is the value
		virtual ~TreeNode(); //virtual destructor will be used when you'll make 
		//templates and inheritance so you can have the same method for every 
		//child class from this base class
		TreeNode *left;
		TreeNode *right;
		int key;
		T* data;
};

template <class T>
TreeNode<T>::TreeNode() {
	key = 0;
	left = NULL;
	right = NULL;
}
template <class T>
TreeNode<T>::TreeNode(int k){
	left = NULL;
	right = NULL;
	key = k;
}
template <class T>
TreeNode<T>::~TreeNode(){
	//research it
}
