#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode() {
	key = 0;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(int k){
	left = NULL;
	right = NULL;
	key = k;
}

TreeNode::~TreeNode(){
	//research it
}
