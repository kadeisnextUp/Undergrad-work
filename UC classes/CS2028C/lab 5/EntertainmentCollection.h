#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H
#include <new> // Needed for bad_alloc exception
#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int MAX_COLLECTION = 10; // global constant 



template <class T>
class EntertainmentCollection {
private:
    //array of items
    T* collection[MAX_COLLECTION];
    int objects_num;

public:

    EntertainmentCollection() : objects_num(0) {
        for (int i = 0; i < MAX_COLLECTION; i++)
            collection[i] = nullptr;
    }

    void add(T* item) {
        if (objects_num >= MAX_COLLECTION)
            //array is full
            throw std::runtime_error("Collection is full");
        collection[objects_num++] = item;
    }

    void remove() {
        if (objects_num == 0)
            //array is empty
            throw std::runtime_error("Collection is empty");
        objects_num--;
        delete collection[objects_num];
        collection[objects_num] = nullptr;
    }

    int getCollection_num() const {
        return objects_num;
    }

    void displayCollection() const {
        if (objects_num == 0) {
            cout << "The collection is empty." << endl;
        }
        else {
            cout << "Items in the collection:" << endl;
            for (int i = 0; i < objects_num; i++) {
                cout << "- " << collection[i]->getTitle() << endl;
            }
        }
    }
};

    




#endif