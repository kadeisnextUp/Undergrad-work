#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include "HashTable.h"
#include "DoubleLinkedListLab.h"
#include "Student.h"

class ChainedHashTable : public HashTable {
private:
    DoubleLinkedList<Student>* table;  //array of linked lists for chaining
    int hash(const int& key) const;  // hash function declaration
    mutable int comparisonCount;
public:
    ChainedHashTable(int size = 100);
    ~ChainedHashTable();

    bool addItem(Student* student);
    Student* removeItem(const int& num);
    Student* getItem(const int& num) const;
    int getLength() const override;
    
    //probe count
    int getComparisonCount() const { return comparisonCount; }
    void resetComparisonCount() { comparisonCount = 0; }
};

#endif
