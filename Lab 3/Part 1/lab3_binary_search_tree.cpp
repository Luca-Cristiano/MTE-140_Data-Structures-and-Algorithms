#include <iostream>
#include <queue>
#include "lab3_binary_search_tree.hpp"

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL;
	size = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {
	TaskItem* cur = root;
	
	clean_up(cur);
			
	root = NULL;
	size = 0;
}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	if(size == 0) return BinarySearchTree::TaskItem(-1, "N/A");
	TaskItem* cur = root;
	while(cur && cur-> right){
		cur = cur->right;
	}
	return *cur;
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	if(size == 0) return BinarySearchTree::TaskItem(-1, "N/A");
	TaskItem* cur = root;
	while(cur && cur-> left){
		cur = cur->left;
	}
	return *cur;
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
	TaskItem* cur = root;
	queue<TaskItem*> q;
	if(root == NULL) return 0;
	
	q.push(cur);
	int height = 0;
	
	while(1)
	{
		int count = q.size();
		if(count == 0)
			return height;
		height++;
		
		while(count > 0)
		{
			TaskItem* temp = q.front();
			q.pop();
			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
			
			count--;
		}
	}
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
		TaskItem* cur = root;
		TaskItem* key = &val;
		while(cur)
		{
			if(cur->priority == key->priority)
				return true;
			if(key->priority < cur->priority)
				cur = cur->left;
			else
				cur = cur->right;
				
		}
	return false;
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return NULL;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return NULL;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
	TaskItem** cur = &root; //cur -> root -> root value
	TaskItem* value = &val;
	while(*cur)
		{
			if((*cur)->priority == value->priority)
				return false;
			if(value->priority < (*cur)->priority)
				cur = &((*cur)->left); //point to the location where *cur  left pointer is stored
			else
				cur = &((*cur)->right);				
		}
		
		*cur = new TaskItem(val);
		++size;
    return true;
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {	
		
	return false;
}

void BinarySearchTree::clean_up(TaskItem* T)
{
	if (T == NULL) return;
	clean_up(T->left);
	clean_up(T->right);
	delete T;
}
