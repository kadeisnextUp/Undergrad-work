#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class HashTable2D {
private:
    static const int ROWS = 100;
    static const int COLS = 5;
    int table[ROWS][COLS];

public:
    HashTable2D() {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                table[i][j] = -1;
    }

    ~HashTable2D() {}
    /* Create a hash table that uses 2D arrays with 100 slots each 5 deep. Once the 5 are full,
        the items can’t be stored in that slot
    */
    int hashFunction(int value) {
        return value % ROWS;
    }
    // all fucntions work the same as hashTable1D

    int insert(int value) {
        int row = hashFunction(value);
        int slotsChecked = 1;

        for (int col = 0; col < COLS; col++) {
            if (table[row][col] == -1) {
                table[row][col] = value;
                return slotsChecked;
            }
            slotsChecked++;
        }
        throw runtime_error("Slot is full");
    }

    int find(int value) {
        int row = hashFunction(value);
        int slotsChecked = 1;

        for (int col = 0; col < COLS; col++) {
            if (table[row][col] == value)
                return slotsChecked;
            if (table[row][col] == -1)
                break;
            slotsChecked++;
        }
        return slotsChecked;
    }

    int remove(int value) {
        int row = hashFunction(value);
        int slotsChecked = 1;

        for (int col = 0; col < COLS; col++) {
            if (table[row][col] == value) {
                table[row][col] = -1;
                return slotsChecked;
            }
            if (table[row][col] == -1)
                break;
            slotsChecked++;
        }
        return slotsChecked;
    }

    void print() const {
        for (int i = 0; i < ROWS; i++) {
            bool rowEmpty = true;
            cout << "Row " << setw(2) << i << ": ";

            for (int j = 0; j < COLS; j++) {
                if (table[i][j] != -1) rowEmpty = false;
                cout << (table[i][j] == -1 ? "[ ]" : "[" + to_string(table[i][j]) + "]") << " ";
            }

            if (rowEmpty) cout << " (empty)";
            cout << endl;
        }
    }
};

#endif