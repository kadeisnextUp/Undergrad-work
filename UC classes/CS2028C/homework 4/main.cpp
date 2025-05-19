#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include "HashTable1D.h"
#include "HashTable2D.h"
#include "BinarySearchTree.h"

using namespace std;

vector<int> generateUniqueRandomNumbers(int count) {
    vector<int> numbers;
    srand(time(0));

    while (numbers.size() < count) {
        int num = rand() % 1000 + 1;
        if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
            numbers.push_back(num);
        }
    }
    return numbers;
}

void printResults(const string& operation, int check1D, int check2D, int checkBST) {
    cout << "\n=== " << operation << " ===" << endl;
    cout << "1D Hash Table probes: " << check1D << endl;
    cout << "2D Hash Table probes: " << check2D << endl;
    cout << "BST probes:           " << checkBST << endl;
}

int main() {
    //generate random numbers
    vector<int> dataset = generateUniqueRandomNumbers(100);

    //initialize data structures
    HashTable1D ht1d;
    HashTable2D ht2d;
    BinarySearchTree<int> bst;

    //insert first 50 values
    int check1D = 0, check2D = 0, checkBST = 0;
    for (int i = 0; i < 50; i++) {
        check1D += ht1d.insert(dataset[i]);
        check2D += ht2d.insert(dataset[i]);
        checkBST += bst.insert(dataset[i]);
    }
    printResults("Initial Insertion (50 items)", check1D, check2D, checkBST);

    //remove items where value % 7 == 0
    check1D = check2D = checkBST = 0;
    for (int i = 0; i < 50; i++) {
        if (dataset[i] % 7 == 0) {
            check1D += ht1d.remove(dataset[i]);
            check2D += ht2d.remove(dataset[i]);
            checkBST += bst.remove(dataset[i]);
        }
    }
    printResults("Removal (values % 7 == 0)", check1D, check2D, checkBST);

    //insert remaining 50 values
    check1D = check2D = checkBST = 0;
    for (int i = 50; i < 100; i++) {
        check1D += ht1d.insert(dataset[i]);
        check2D += ht2d.insert(dataset[i]);
        checkBST += bst.insert(dataset[i]);
    }
    printResults("Second Insertion (50 items)", check1D, check2D, checkBST);

    //find items where value % 9 == 0
    check1D = check2D = checkBST = 0;
    for (int i = 0; i < 100; i++) {
        if (dataset[i] % 9 == 0) {
            check1D += ht1d.find(dataset[i]);
            check2D += ht2d.find(dataset[i]);
            checkBST += bst.find(dataset[i]);
        }
    }
    printResults("Search (values % 9 == 0)", check1D, check2D, checkBST);

    return 0;
}