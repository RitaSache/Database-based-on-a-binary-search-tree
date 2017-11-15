
#include "TreeNode.h"
using namespace std;
template <class T>
class BST { //implement the 3 ways of that tree, pre, post, and in order (code written in notes)
	public:
		BST();
		virtual ~BST();
		void insert(int value);
		bool contains(T value); //like find
		bool deleteNode(T value);
		T* getSuccessor(T *d); //for deleting a node
		T* getMin();
		T* getMax();
		void printTree();
		bool isEmpty();
	private:
		TreeNode *root;
};

template <class T>
BST<T>::BST(){
	root = NULL;
}
template <class T>
BST<T>::~BST(){
	//research it
	//iterate and delete
}
template <class T>
T* BST<T>::getMin(){ //curr to keep track where we are as we navigate through tree
	T *current = root; //start at root
	if(root == NULL) {
		return NULL;
	}
	while(current->left != NULL){ //keep iterating if left node isnt null
		current = current -> left; //all the way down to the left
	}
	return current; //node with smallest value or current -> key or value or data
}
template <class T>
T* BST<T>::getMax(){
	T *current = root; //start at root
	if(root == NULL) {
		return NULL;
	}
	while(current->right != NULL){ //keep iterating if left node isnt null
		current = current -> right; //all the way down to the right
	}
	return current;
}
template <class T>
void BST<T>::insert(int value){
	TreeNode *newNode = new TreeNode(value);
	if (root == NULL) {//if tree is empty
		root = newNode;
	}
	else{ //not empty, find where will new node go. need placeholders
		TreeNode *current = root;
		TreeNode *parent; //parent is one node up. empty pointer to node
		while(true){
			parent = current; //update current at every iteration and it will be one node down
			if(value < current->key) {//test if smaller or larger
				current = current->left;
				if(current == NULL) {//found the position, where parent is right above the null node
					parent->left = newNode; //place new node to the left of the parent
					break;
				}
			} 
			else{//go right
				if(value > current->key) {
					current = current->right;
					if(current==NULL){
						parent->right = newNode;
						break;
					}
				}
			}
		}
	}
}
template <class T>
bool BST<T>::contains(T value){
	if(root == NULL){
		return false;
	}
	else{
		T *current = root;
		while(current->key != value){ //while this key doesnt equal value we will keep iterating
			if(value < current -> key){
				current = current -> left;
			}
			else{
				current = current -> right;
			}
			if(current == NULL) {
				return false;
			}	
		}
	}
	return true;
}
template <class T>
bool BST<T>::deleteNode(T k){
	//didnt go over it, will be around 3 pages long. read about it in the book
	//check if it's a leaf, has one child, or two children
	//getSuccessor() is for finding the replacement of a deleted node with two children. cant just replace with a random node cause it's ruin the tree
	if(root == NULL) {//tree is empty
		return false;
	}
	T *current = root;
	T *parent = root; //so we can update node's right and left neighbor accordingly
	bool isLeft = true;

	while(current->key != k)
	{
		parent = current;
		if (k < current -> key) // go left
		{
			isLeft = true;
			current = current -> left;
		}
		else {
			isLeft = false;
			current = current -> right;
		}

		if (current == NULL){
			return false;
		}
	}
	//if we get here we found the node we want to delete
	//deleting a node with no children
	if(current->left == NULL && current->right == NULL){
		if(current == root) {//leaf and root are the same in this case
			root = NULL;
		}
		else if(isLeft){//we have at least 1 node and it's a left node
			parent ->left = NULL;
		}
		else{
			parent ->right = NULL;
		}
	}
	else if(current->right == NULL){//deleting a root node with one child 
		if(current == root) {
			root = current -> left; //root now becomes the current's node's left child
		}
		else if(isLeft){
			parent->left = current -> left;
		}
		else{ //it's a right child
			parent->right = current->right;
		}
	}
	else if(current->left ==NULL){//exact opposite of above condition, but for right child
		if(current==root){
			root = current->right;
		}
		else if(isLeft){
			parent->left = current -> right;
		}
		else{
			parent->right = current->right;
		}
	}
	else{//a node has two children
		T *successor = getSuccessor(current);

		if(current == root){
			root =successor;
		}
		else if(isLeft){
			parent->left=successor;
		}
		else{
			parent->right= successor;
		}
		successor->left = current->left;
	}
	return true;
}
template <class T>
T* BST<T>::getSuccessor(T *d){
	T *sp = d;
	T *successor =d;
	T *current = d->right;

	while(current !=NULL){
		sp= successor;
		successor= current;
		current=current->left;
	}
	if(successor != d->right){
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}
