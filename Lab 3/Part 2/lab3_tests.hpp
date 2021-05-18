#ifndef LAB3_TESTS_HPP
#define LAB3_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include <algorithm>
#include <sstream>
#include <queue>
#include <iostream>
#include "lab3_priority_queue.hpp"

using namespace std;
class PriorityQueueTest {
public:
	// PURPOSE: Tests if the new queue is valid
	bool test1() {
		PriorityQueue q(5);
		ASSERT_TRUE( q.empty() );
		ASSERT_TRUE( !q.full() );
		ASSERT_TRUE( q.get_size() == 0 );
		return true;
	}

	// PURPOSE: Tests enqueue of one item and then dequeue of that item
	bool test2() {
		PriorityQueue q(2);
		
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(10,"Test Task")) );
		ASSERT_TRUE( !q.empty() );
		ASSERT_TRUE( !q.full() );
		ASSERT_TRUE( q.get_size() == 1 );
		ASSERT_TRUE( q.max().priority == 10 );

		
		ASSERT_TRUE( q.dequeue() );
		ASSERT_TRUE( q.empty() );
		ASSERT_TRUE( !q.full() );
		ASSERT_TRUE( q.get_size() == 0 );
		return true;
	}

	// PURPOSE: Tests enqueue too many
	bool test3() {
		PriorityQueue q(3);
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(5,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(3,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(4,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.full() );

		ASSERT_TRUE( !q.enqueue(PriorityQueue::TaskItem(7,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.full() );
		return true;
	}
  
	// PURPOSE: Tests enqueue too many then dequeue too many
	bool test4() {
		PriorityQueue q(3);
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(5,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		
		//q.print();
		
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(3,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		
		//q.print();
		
		ASSERT_TRUE( q.enqueue(PriorityQueue::TaskItem(4,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.full() );

		//q.print();

		ASSERT_TRUE( !q.enqueue(PriorityQueue::TaskItem(7,"Test Task")) );
		ASSERT_TRUE( q.max().priority == 5 );
		ASSERT_TRUE( q.full() );

		//q.print();

		ASSERT_TRUE( q.dequeue() );
		ASSERT_TRUE( q.max().priority == 4 );
		ASSERT_TRUE( q.dequeue() );
		ASSERT_TRUE( q.max().priority == 3 );
		ASSERT_TRUE( q.dequeue() );
		ASSERT_TRUE( q.empty() );
		ASSERT_TRUE( !q.full() );

		ASSERT_TRUE( !q.dequeue() );
		ASSERT_TRUE( q.empty() );
		ASSERT_TRUE( !q.full() );
		return true;
	}
};
#endif
