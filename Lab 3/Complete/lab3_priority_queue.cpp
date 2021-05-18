//Bryan Guan (20844857), Aidan Walker (20823540), Luca Cristiano (20843293)
#include "lab3_priority_queue.hpp"
#include <iostream>

using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	heap = new TaskItem*[n_capacity + 1];
	capacity = n_capacity;
	size = 0;
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
	for (int i = 1; i <= size; ++i)
	{
		delete heap[i];
		heap[i] = NULL;
	}
	
	delete []heap;
	heap = NULL;

}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
		return size == 0;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return size == capacity;
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
	for (int i = 1; i <= size; i++){
		cout << heap[i]->priority << endl;
	}
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
	if(empty())
		return TaskItem(-1, "NULL");
	
	return *heap[1];	
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	if(size == capacity)
		return false;
	
	if(size == 0)
	{
		heap[1] = new TaskItem(val);
	}
	else{
		int i = size + 1;
		heap[i] = new TaskItem(val);
		while(i > 1 && heap[i/2]->priority < heap[i]->priority)
		{
			TaskItem* temp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = temp;
			i /= 2;
		}
	}
	size++;
	return true;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	if(empty())
		return false;
	if(size == 1)
	{
		delete heap[1];
		heap[1] = NULL;
		--size;
		return true;
	}	
	else{
		delete heap[1];
		heap[1] = heap[size];
		heap[size] = NULL;
		size--;
		
		TaskItem* temp = heap[1];
		int i = 1;
		while(i < size) // check if left child present
		{
			if (heap[2 * i] && heap[2 * i + 1]){ // add the priority to comparison
				if (heap[2 * i]->priority > heap[2 * i + 1]->priority && heap[i * 2]->priority > temp->priority){
					heap[i] = heap[2 * i];
					heap[2 * i] = temp;
					i = 2*i;
				}
				else if (heap[2 * i]->priority < heap[2 * i + 1]->priority && heap[i * 2 + 1]->priority > temp->priority){
					heap[i] = heap[2 * i + 1];
					heap[2 * i + 1] = temp;
					i = 2*i + 1;
				}	
				else 
					return true;
			}
			else if (heap[2 * i]){
				if (heap[2 * i]->priority > temp->priority){
					heap[i] = heap[2 * i];
					heap[2 * i] = temp;
					i = 2*i;
				}
				else
					return true;
			}
			
			else 
				return false;
			
		} 
		
	}
	return true;
}
