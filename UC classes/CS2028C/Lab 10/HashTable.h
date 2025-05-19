// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

using namespace std;
// This class implements a hash table for storing Student objects
// provides methods to add, remove, and retrieve students by name
// uses linear probing for collision resolution

class HashTable {
protected:
    Student** table;
    int max_size;
    int current_size;
    mutable int probeCount;

    int hash(const int& key) const;

public:
    HashTable(int size = 100);
    virtual ~HashTable();

    bool addItem(Student* student);
    Student* removeItem(const int& num);
    Student* getItem(const int& num) const;
    virtual int getLength() const;

    //probe counting stuff
    int getProbeCount() const { return probeCount; }
    void resetProbeCount() { probeCount = 0; }

};

#endif
