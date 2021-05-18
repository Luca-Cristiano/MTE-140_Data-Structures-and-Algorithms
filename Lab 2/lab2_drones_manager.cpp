//Bryan Guan (20844857), Aidan Walker (20823540), Luca Cristiano (20843293)
#include "lab2_drones_manager.hpp"
#include <cstdlib>
#include <iostream>
// TODO: Implement all of the listed functions below
using namespace std;

DronesManager::DronesManager() {
	first = NULL;
	last = NULL;
	size = 0;	
}

DronesManager::~DronesManager() {
	DroneRecord* del_Drone = first;
	DroneRecord* temp = first;
		
	while (del_Drone != NULL){
		temp = del_Drone -> next;
		
		
		delete (del_Drone);
		del_Drone = NULL;
		
		del_Drone = temp;
	}
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.droneID == rhs.droneID && lhs.batteryType == rhs.batteryType && lhs.description == rhs.description &&
	lhs.droneType == rhs.droneType && lhs.manufacturer == rhs.manufacturer &&
	lhs.range == rhs.range && lhs.yearBought == rhs.yearBought);
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return (first == NULL && last == NULL);
}
//changed select function
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	DroneRecord *temp = first;
	if(empty())
		return DroneRecord(0);
	else if(index >= size)
		return *last;
	else
	{
		for (unsigned int i = 0; i < index && temp->next != NULL; i++){
		temp = temp->next;
		}
	}	
	return *temp;
}
//Changed search function
unsigned int DronesManager::search(DroneRecord value) const {
	if (!first)
		return 0;
		
	DroneRecord *temp = new DroneRecord(*first);
	int counter = 0;

	while (temp->next != NULL && !(*temp == value)){
		counter++;
		temp = temp->next;
	}
	if (*temp == value) {
		delete temp;
		temp = NULL;
		return counter;	
	}
	delete temp;
	temp = NULL;
	return size;
}

void DronesManager::print() const {
	DroneRecord* curr = first;
	
	cout<<"------------------------------------------------------"<<endl;
	
	while(curr != NULL)
	{
		cout<<"DroneID: "<<curr->droneID<<endl<<"Range: "<<curr->range<<endl
		<<"yearBought: "<<curr->yearBought<<endl<<"DroneType: "<<curr->droneType<<endl
		<<"Manufacturer: "<<curr->manufacturer<<endl<<"Description: "<<curr->description<<endl
		<<"batteryType: "<<curr->batteryType<<endl;
		curr = curr->next;
		
		cout<<"------------------------------------------------------"<<endl;
	}
}
//changed insert 
bool DronesManager::insert(DroneRecord value, unsigned int index) {
	DroneRecord* curr = first;
	DroneRecord* insertVal = new DroneRecord(value);

	if(index > size)
		return false;
	
	for(int i = 0; i < index-1; i++)
	{
		curr = curr->next;
	}
	
	insertVal->next = curr->next;
	insertVal->prev = curr;
	curr->next = insertVal;
	insertVal->next->prev = insertVal;
	
	++size;
	return true;
}
//changed insert_front 
bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* insertVal = new DroneRecord(value);
	if(empty())
	{
		first = insertVal;
		last = insertVal;
		insertVal->prev = NULL;
		insertVal->next = NULL;
	}
	else
	{
		insertVal->next = first;
		first->prev = insertVal;
		insertVal->prev = NULL;
		first = insertVal;
	}
	
	++size;
	
	return true;
}
//changed insert_back
bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* insertVal = new DroneRecord(value);

	if(empty())
	{
		last = insertVal;
		first = insertVal;
		insertVal->next = NULL;
		insertVal->prev = NULL;
	}
	else
	{
		last->next = insertVal;
		insertVal->prev = last;
		insertVal->next = NULL;
		last = insertVal;
	}
	
	++size;
	return true;
}
//added if (index > size || index < 0)
bool DronesManager::remove(unsigned int index) {
    if (first == NULL){
		return false;
	}
	
	if (index == 0){
		remove_front();
		return true;
	}
	
	if (index == get_size() - 1){
		remove_back();
		return true;
	}
	
	if (index >= size){
		cout << "Please enter an index betweeen 0 and size - 1.";
		return false;
	}
	
	DroneRecord* prev = first;
	DroneRecord* delete_Pos = first;
	DroneRecord* next = first;
	
	for (int i = 0; i < index && prev != NULL; i++){
		delete_Pos = delete_Pos -> next;
	}
	
	next = delete_Pos -> next;
	prev = delete_Pos -> prev;
	
	prev -> next = next;
	next -> prev = prev;
	
	delete (delete_Pos);
	delete_Pos = NULL;
	
	--size;
		
	return true;
}

bool DronesManager::remove_front() {
    if (first == NULL){
        return false;
	}

    if (first -> next == NULL){
		delete (first);
		first = NULL;
		last = NULL;
		--size;
		return true;
	}

    DroneRecord* delete_Pos = first;

    first = first -> next; // if first next is null then first is now null, so next line tries to dereference null
	first -> prev = NULL;
	delete (delete_Pos);
	delete_Pos = NULL;
	--size;

    if (size == 1){
		last = first;
	}

    return true;
}

bool DronesManager::remove_back() {
	if (first == NULL){
		return false;
	}
	
	if (first -> next == NULL){
		delete (first);
		first = NULL;
		last = NULL;
		
		--size;
		
		return true;
	}
	
	DroneRecord* delete_Pos = first;
	DroneRecord* prev = first;
	
	while (delete_Pos -> next != NULL){
		delete_Pos = delete_Pos -> next;
	}
	
	prev = delete_Pos -> prev;
	prev -> next = NULL;
	
	last = prev;
	
	delete(delete_Pos);
	delete_Pos = NULL;
	
	--size;
	
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	DroneRecord* curr = first;
	DroneRecord* insertVal = new DroneRecord(value);

	if(index > size || index < 0)
		return false;
	
	if(empty()){
		insert_front(value);
	}	
	
	else if (index == 0 && size == 1)
	{
		delete (curr);
		curr = NULL;

		first = insertVal;
		last = insertVal; 
		
		insertVal->next = NULL;
		insertVal->prev = NULL;	
	}
	else
	{
		for(int i = 0; i < index-1; i++)
			curr = curr->next;
		
		DroneRecord* temp = curr->next;
		curr->next = insertVal;
		temp->next->prev = insertVal;
		insertVal->prev = curr;
		insertVal->next = temp->next;
		
		delete temp;
		temp = NULL;	
	}
	
	return true;
}

bool DronesManager::reverse_list() {
	if (first == NULL){
		return false;
	}
	
	DroneRecord* temp = NULL;
	DroneRecord* tempFirst = first;
	DroneRecord* tempLast = last;
    DroneRecord* current = first;
    
    while (current != NULL){
    	temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev; 
	}

	first = tempLast;
	last = tempFirst;
    
    return true;
}



