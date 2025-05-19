#ifndef DOUBLELINKEDLISTLAB_H
#define DOUBLELINKEDLISTLAB_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class DoubleLinkedList {
private:
    struct listNode {
        T* value;
        listNode* next;
        listNode* prev;
    };
    listNode* head;
    listNode* tail;
    listNode* cursor; 

public:
    // constructor
    DoubleLinkedList() : head(nullptr), tail(nullptr), cursor(nullptr) {}

    // destructor
    ~DoubleLinkedList();

    // required functions
    void addItem(T* item);
    T* getItem(const T* item);
    bool IsInList(const T* item) const;
    bool IsEmpty() const;
    int size() const;
    T* seeNext();
    T* seePrev();
    T* seeAt(const T* item, int& comparisonCount) const;
    void reset();
    void display();
   

};

// destructor
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    listNode* nodePtr = head;
    while (nodePtr != nullptr) {
        listNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
    head = tail = cursor = nullptr;
}

// adds an item in order
template <class T>
void DoubleLinkedList<T>::addItem(T* item) {
    listNode* tempNode = new listNode{ item, nullptr, nullptr };

    if (IsEmpty()) {
        head = tail = tempNode;
    }
    else {
        listNode* nodePtr = head;
        listNode* previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value < item) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr) {
            tempNode->next = head;
            head->prev = tempNode;
            head = tempNode;
        }
        else if (nodePtr == nullptr) {
            previousNode->next = tempNode;
            tempNode->prev = previousNode;
            tail = tempNode;
        }
        else {
            previousNode->next = tempNode;
            tempNode->next = nodePtr;
            tempNode->prev = previousNode;
            nodePtr->prev = tempNode;
        }
    }
}

// removes and returns an item from the list
template <class T>
T* DoubleLinkedList<T>::getItem(const T* item) {
    listNode* nodePtr = head;

    while (nodePtr != nullptr && *(nodePtr->value) != *item) {
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr) {
        return nullptr;
    }

    // Update list pointers
    if (nodePtr == head) {
        head = nodePtr->next;
        if (head != nullptr) head->prev = nullptr;
    }
    else if (nodePtr == tail) {
        tail = nodePtr->prev;
        if (tail != nullptr) tail->next = nullptr;
    }
    else {
        nodePtr->prev->next = nodePtr->next;
        if (nodePtr->next != nullptr) nodePtr->next->prev = nodePtr->prev;
    }

    T* itemValue = nodePtr->value;
    delete nodePtr;
    return itemValue;
}

// checks if item is in the list
template <class T>
bool DoubleLinkedList<T>::IsInList(const T* item) const{
    listNode* nodePtr = head;

    while (nodePtr != nullptr) {
        if (nodePtr->value > *item) return false;
        if (nodePtr->value == *item) return true;
        nodePtr = nodePtr->next;
    }
    return false;
}

// checks if list is empty
template <class T>
bool DoubleLinkedList<T>::IsEmpty() const {
    return head == nullptr;
}

// returns number of items in the list
template <class T>
int DoubleLinkedList<T>::size() const {
    int count = 0;
    listNode* nodePtr = head;
    while (nodePtr != nullptr) {
        count++;
        nodePtr = nodePtr->next;
    }
    return count;
}

// returns the next item in the list
template <class T>
T* DoubleLinkedList<T>::seeNext() {
    if (IsEmpty()) throw std::runtime_error("List is empty");
    if (cursor == nullptr) throw std::runtime_error("No more items");

    T result = cursor->value;
    cursor = cursor->next;
    return result;
}

// returns the previous item in the list
template <class T>
T* DoubleLinkedList<T>::seePrev() {
    if (IsEmpty()) throw std::runtime_error("List is empty");
    if (cursor == nullptr || cursor->prev == nullptr) throw std::runtime_error("No previous item");

    cursor = cursor->prev;
    return cursor->value;
}

//sees item by value for the hash table
template <class T>
T* DoubleLinkedList<T>::seeAt(const T* item, int& comparisonCount) const {
    if (IsEmpty()) return nullptr;

    listNode* nodePtr = head;
    while (nodePtr != nullptr) {
        comparisonCount++; //increment for comparison
        if (*(nodePtr->value) == *item)
            return nodePtr->value;
        nodePtr = nodePtr->next;
    }

    return nullptr;
}


// resets the seeNext location
template <class T>
void DoubleLinkedList<T>::reset() {
    cursor = head;
}

// displays the list contents
template <class T>
void DoubleLinkedList<T>::display() {
    listNode* nodePtr = head;
    while (nodePtr != nullptr) {
        nodePtr->value.Display(); // T must have Display() method
        nodePtr = nodePtr->next;
    }
}



#endif

