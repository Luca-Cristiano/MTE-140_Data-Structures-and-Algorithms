#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"
#include <iostream>

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

using namespace std;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {	
		DronesManager manager1, manager2;
		for(int i = 0; i < 4; i++)
			manager1.insert_back(DronesManager::DroneRecord(i));
			
		ASSERT_TRUE(manager1.get_size() == 4 && manager2.get_size()==0)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.select(4) == DronesManager::DroneRecord(0))
		ASSERT_TRUE(manager1.select(-1) == manager1.select(5) && manager1.select(-1) == DronesManager::DroneRecord(3))
		ASSERT_TRUE(manager1.search(DronesManager::DroneRecord(100)) == 4)
		ASSERT_TRUE(manager2.search(DronesManager::DroneRecord(5)) == 0)
	    return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
	    DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(12));
		manager1.insert_back(DronesManager::DroneRecord(15));
		manager1.insert_back(DronesManager::DroneRecord(20));
		manager2.insert_front(DronesManager::DroneRecord(15));
		
		manager1.remove_front();
		
		manager1.remove_back();
		
		//testing print
		manager1.print();
		
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(15))
	    return true;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		DronesManager manager1;
	    manager1.insert_front(DronesManager::DroneRecord(100));
    	manager1.insert_front(DronesManager::DroneRecord(200));
	    manager1.insert_front(DronesManager::DroneRecord(400));
	    manager1.replace(1, DronesManager::DroneRecord(500));
	    ASSERT_TRUE(manager1.select(1) == DronesManager::DroneRecord(500))

	    DronesManager manager2;
	    ASSERT_FALSE(manager2.replace(1, DronesManager::DroneRecord(500)))
	    
	    DronesManager manager3;
	    manager3.replace(0, DronesManager::DroneRecord(500));
	    ASSERT_FALSE(manager3.first == NULL)
	    
	    manager3.insert_front(DronesManager::DroneRecord(100));
	    manager3.insert_front(DronesManager::DroneRecord(200));
	    manager3.insert_front(DronesManager::DroneRecord(400));
	    
	    manager3.reverse_list();

	    ASSERT_TRUE(*manager3.first == DronesManager::DroneRecord(500))
	    ASSERT_TRUE(*manager3.last == DronesManager::DroneRecord(400))
	    ASSERT_TRUE(*(manager3.last->prev) == DronesManager::DroneRecord(200))
	    ASSERT_TRUE(*(manager3.first->next) == DronesManager::DroneRecord(100))
 
	   	DronesManager manager4;
	   	
	   	ASSERT_FALSE(manager4.reverse_list())
	   	
	   	ASSERT_TRUE(manager4.first == NULL)
	   	
	    return true;
	    
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		DronesManager manager1;
		
		manager1.insert_back(DronesManager::DroneRecord(15));
		manager1.insert_back(DronesManager::DroneRecord(20));
		manager1.insert_front(DronesManager::DroneRecord(12));
		
		ASSERT_TRUE(manager1.get_size() == 3)
		ASSERT_TRUE(*manager1.first == DronesManager::DroneRecord(12))
		ASSERT_TRUE(*manager1.first -> next == DronesManager::DroneRecord(15))
		ASSERT_TRUE(*manager1.first -> next -> next == DronesManager::DroneRecord(20))
	    return true;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		DronesManager manager1, manager2;
		for(int i = 0; i < 4; i++)
			manager1.insert_back(DronesManager::DroneRecord(i));
		
		manager2.insert_back(DronesManager::DroneRecord(0));
		manager2.insert_back(DronesManager::DroneRecord(1));
		manager2.insert_back(DronesManager::DroneRecord(3));
		
		ASSERT_TRUE(manager1.get_size() == 4 && manager2.get_size() == 3)
		
		manager2.insert(DronesManager::DroneRecord(2), 2);
	
		ASSERT_TRUE(manager1.select(2) == manager2.select(2) && manager2.select(2) == DronesManager::DroneRecord(2))
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager2.get_size() == 4)
		ASSERT_TRUE(manager2.insert(DronesManager::DroneRecord(4),5) == false && manager2.insert(DronesManager::DroneRecord(-1),-1) == false)
		
	    return true;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager manager1, manager2;
		
		manager1.insert_back(DronesManager::DroneRecord(2));
		manager1.insert_back(DronesManager::DroneRecord(3));
		manager1.insert_front(DronesManager::DroneRecord(1));
		
		
		manager1.remove(1);
		manager1.remove_front();
		manager1.remove_back();
		manager1.remove_front();
		manager1.remove_back();
		
		ASSERT_TRUE(manager1.first == NULL)
		ASSERT_TRUE(manager1.get_size() == 0)
				
		manager1.insert_back(DronesManager::DroneRecord(23));
		manager1.insert_back(DronesManager::DroneRecord(34));
		
		manager2.insert_back(DronesManager::DroneRecord(23));
		manager2.insert_back(DronesManager::DroneRecord(34));
		
		ASSERT_TRUE(*manager1.first == *manager2.first)
		ASSERT_TRUE(*manager1.first -> next == *manager2.first -> next)
		
	    return true;	
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(2));
		manager1.insert_back(DronesManager::DroneRecord(3));
		manager1.insert_front(DronesManager::DroneRecord(0));
		manager1.insert(DronesManager::DroneRecord(1),1);
		
		for(int i = 0; i < 4; i++)
			ASSERT_TRUE(manager1.select(i) == DronesManager::DroneRecord(i))
			
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(-2),-2) == false)
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(100),100) == false)
		ASSERT_TRUE(manager2.insert(DronesManager::DroneRecord(10),100) == false)

		
		ASSERT_TRUE(manager2.remove(0) == false);
		manager1.remove_front();
		manager1.remove_back();
		manager1.remove(1);
		ASSERT_TRUE(manager1.get_size() == 1)
		ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(1))
		manager1.remove_front();
		ASSERT_TRUE(manager1.get_size() == 0)
		ASSERT_TRUE(manager2.remove(10) == false && manager2.remove(-1) == false)
			
		return true;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
		DronesManager manager;
		for (int i = 0; i < 15; i++){
			manager.insert_front(i);
		}
		DronesManager::DroneRecord* temp = manager.first;
		for (int i = 15; i > 0; i--){
			ASSERT_TRUE(*temp == DronesManager::DroneRecord(i - 1))
			temp = temp->next;
		}
		
		manager.reverse_list();
		
		temp = manager.first;
		for (int i = 0; i < 15; i++){
			ASSERT_TRUE(*temp == DronesManager::DroneRecord(i))
			temp = temp->next;
		}
		
		for (int i = 0; i < 15; i++){
			manager.remove_front();
		}
		
		ASSERT_TRUE(manager.first == NULL && manager.last == NULL && manager.size == 0)
		
	   	return true;
	} 
	
};

#endif
