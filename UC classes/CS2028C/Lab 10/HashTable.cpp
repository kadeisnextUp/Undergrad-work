// HashTable.cpp
#include "HashTable.h"
#include <iostream>

using namespace std;
// HashTable class implementation


HashTable::HashTable(int size) : max_size(size), current_size(0) {
    table = new Student*[max_size];
    for (int i = 0; i < max_size; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < max_size; ++i) {
        delete table[i];  
    }
    delete[] table;
}

int HashTable::hash(const int& key) const {
    return key % max_size;
}

bool HashTable::addItem(Student* student) {
    if (current_size >= max_size) return false;

    int index = hash(student->getMnumber());
    int startIndex = index;

    do {
        if (table[index] == nullptr) {
            table[index] = student;
            current_size++;
            return true;
        }
        index = (index + 1) % max_size;
    } while (index != startIndex);

    return false; // the table is full
}

Student* HashTable::removeItem(const int& num) {
    int index = hash(num);
    int startIndex = index;

    do {
        if (table[index] != nullptr && table[index]->getMnumber() == num) {
            Student* removed = table[index];
            table[index] = nullptr;
            current_size--;

            // rehash items that are in cluster
            int next = (index + 1) % max_size;
            while (table[next] != nullptr) {
                Student* rehashItem = table[next];
                table[next] = nullptr;
                current_size--;
                addItem(rehashItem);
                next = (next + 1) % max_size;
            }

            return removed;
        }
        index = (index + 1) % max_size;
    } while (index != startIndex);

    return nullptr;
}

Student* HashTable::getItem(const int& num) const {
    int index = hash(num);
    int startIndex = index;

    do {
        probeCount++;
        if (table[index] != nullptr && table[index]->getMnumber() == num) {
            return table[index];
        }
        index = (index + 1) % max_size;
    } while (index != startIndex);

    return nullptr;
}

int HashTable::getLength() const {
    return current_size;
}
