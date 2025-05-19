#include "ChainedHashTable.h"
#include "DoubleLinkedListLab.h"
#include <iostream>
using namespace std;

// Constructor: Initialize the table with linked lists
ChainedHashTable::ChainedHashTable(int size) : HashTable(size) {
    table = new DoubleLinkedList<Student>[max_size];  // Allocate array of linked lists
    current_size = 0;
}

// Destructor: Clean up
ChainedHashTable::~ChainedHashTable() {
    delete[] table;
}

// Hash function: mNumber mod table size
int ChainedHashTable::hash(const int& key) const {
    return key % max_size;
}

// Add a student to the hash table
bool ChainedHashTable::addItem(Student* student) {
    int index = hash(student->getMnumber());
    table[index].addItem(student);
    current_size++;
    return true;
}

//removes a student by mNumber
Student* ChainedHashTable::removeItem(const int& num)  {
    int index = hash(num);
    Student temp("", "", num, "");  
    Student* removed = table[index].getItem(&temp);  
  
    if (removed) {
        current_size--;  
    }
    return removed;
}


// Retrieve a student by mNumber
Student* ChainedHashTable::getItem(const int& num) const {
    comparisonCount = 0;  // reset
    int index = hash(num);
    Student temp("", "", num, "");
    return table[index].seeAt(&temp,comparisonCount);
}

int ChainedHashTable::getLength() const
{
    return current_size;
}
