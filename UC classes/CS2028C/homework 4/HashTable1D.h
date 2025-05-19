#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class HashTable1D {
private:
    static const int TABLE_SIZE = 500;
    int table[TABLE_SIZE];

public:
    HashTable1D() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    ~HashTable1D() {}

    int hashFunction(int value) {
        return value % TABLE_SIZE;
    }

    /* accepts a value (integer), runs a hash function on the integer, and places it
        in the hash table. This function should return the number of spots it checks before
        inserting the item in the hash table so if it has no collisions, it should return 1 and
        if it has 3 collisions and then finds a spot on the 4th try, it return 4.
    */
    int insert(int value) {
        int index = hashFunction(value);
        int slotsChecked = 1; 

        for (int i = 0; i < TABLE_SIZE; i++) {
            int probingIndex = (index + i) % TABLE_SIZE;

            if (table[probingIndex] == -1) {
                table[probingIndex] = value;
                return slotsChecked;
            }
            slotsChecked++;
        }

        throw runtime_error("Hash table is full");
    }

    /* accepts a value (integer), locates the value in the hash table and returns the
        number of spots it checked to find the item or determine it is not in the hash table.
        This uses the same procedure as Insert to determine number of spots checked.
    */
    int find(int value) {
        int index = hashFunction(value);
        int slotsChecked = 1;

        for (int i = 0; i < TABLE_SIZE; i++) {
            int probingIndex = (index + i) % TABLE_SIZE;

            if (table[probingIndex] == value)
                return slotsChecked;
            if (table[probingIndex] == -1)
                break;

            slotsChecked++;
        }
        return slotsChecked;
    }

    /* accepts a value (integer), locates the value in the hash table and
        removes it from the hash table. It returns the number of spots it checked to find
        the item or determine it is not in the hash table. This uses the same procedure as
        Insert to determine number of spots checked.
    
    */
    int remove(int value) {
        int index = hashFunction(value);
        int slotsChecked = 1;

        for (int i = 0; i < TABLE_SIZE; i++) {
            int probingIndex = (index + i) % TABLE_SIZE;

            if (table[probingIndex] == value) {
                table[probingIndex] = -1;
                return slotsChecked;
            }
            if (table[probingIndex] == -1)
                break;

            slotsChecked++;
        }
        return slotsChecked;
    }

    /* prints all items in the hash table including an indication of which spots are
        not occupied 
    */
    void print() const {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (i % 10 == 0) cout << "\n" << setw(3) << i << ": ";
            cout << (table[i] == -1 ? "[ ]" : "[" + to_string(table[i]) + "]") << " ";
        }
        cout << endl;
    }
};

#endif