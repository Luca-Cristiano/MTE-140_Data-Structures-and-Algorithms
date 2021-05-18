//Bryan Guan (20844857), Aidan Walker (20823540), Luca Cristiano (20843293)
#include <iostream>
#include <queue>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
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

void BinarySearchTree::clean_up(TaskItem* T)
{
	if (T == NULL) return;
	clean_up(T->left);
	clean_up(T->right);
	delete T;
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
	return get_node_depth(cur);
}

int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	if(n == NULL || (n->left == NULL && n->right == NULL))return 0;
	int l_Depth = get_node_depth(n->left);
    int r_Depth = get_node_depth(n->right);

    if (l_Depth > r_Depth) 
        return(1+l_Depth);
    else return(1+r_Depth);
	
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
	
}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists(BinarySearchTree::TaskItem val) const {
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
    return root;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return &root;
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
//Help was recived by Gabriel Luo. Went over implementation of double pointers
bool BinarySearchTree::remove(BinarySearchTree::TaskItem val) {
	if (root == NULL || size == 0 || exists(val) == false){
		
		return false;
		
	}
        
    TaskItem** del = &root;

	//Find the value correspending to val in the tree
    while((*del) -> priority != val.priority)
    {
        if ((*del) -> priority > val.priority){
			
			del = &((*del) -> left);
			
		}else{
			
            del = &((*del) -> right);
            
        }
    }
	
	//Case: no chicldren, nice and easy just delete the node
    if ((*del) -> left == NULL && (*del) -> right == NULL){
    	
        delete (*del);
        *del = NULL;
        
    //Next case if there is only one child node, first figure out if the node
    //is on the right or left then delete the node and save it the the original
    //right or left (basically cut the node out and glue it together)
    }else if ((*del) -> left != NULL && (*del) -> right == NULL || (*del) -> left == NULL && (*del) -> right != NULL){
    	
        TaskItem* temp = NULL;
        
        if ((*del) -> left){
        	
            temp = (*del) -> left;
            
        }else{
        	
            temp = (*del) -> right;
            
        }
        
        delete (*del);
        *del = NULL;
        *del = temp;
        
    //Finally if the node has two children create another double pointer to the 
    //minimum value of the right side of the tree then 'swap' that value
    //with the node you want to delete. Then effectively repeat the cases above
    //on the node then delete it.
    }else{
    	
        TaskItem** min = del;
        TaskItem* temp = NULL;

        min = &(*min) -> right;

        while ((*min) -> left){
        	
            min = &((*min) -> left);
            
        }
        
		(*del) -> priority = (*min) -> priority;
        (*del) -> description = (*min) -> description;
        

        if ((*min) -> right){
        	
            temp = (*min) -> right;
        
		}
        
        delete (*min);
        *min = NULL;
        *min = temp;
        
    }
    //Don't forget to update the size!
    --size;
    return true;
    
}
