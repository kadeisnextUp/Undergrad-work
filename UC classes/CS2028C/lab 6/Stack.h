#ifndef STACK_H
#define STACK_H

#include <exception> // for custom errors

// custom errors for overflow and underflow
class StackOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack overflow: Cannot push to a full stack";
    }
};

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Cannot pop from an empty stack";
    }
};

template <class T>
class Stack {
private:
    // array of pointers
    T** stacks;
    // size variables
    int maxSize;
    int topPoint;

public:
    // constructor and destructor
    Stack(int size);
    ~Stack();

    // necessary functions
    void push(T* point);
    T* pop();
    T* top();
    int length();
    void empty();
};

// constructor that includes a parameter to determine the size of the array
template <class T>
Stack<T>::Stack(int size) {
    maxSize = size;
    stacks = new T * [maxSize];
    topPoint = -1;
}

// accepts a pointer and adds the pointer to the top of the stack
template <class T>
void Stack<T>::push(T* point) {
    if (topPoint >= maxSize - 1) {
        throw StackOverflowException();
    }
    stacks[++topPoint] = point;
}

// return a pointer
template <class T>
T* Stack<T>::pop() {
    if (topPoint < 0) {
        throw StackUnderflowException();
    }
    return stacks[topPoint--];
}

// return a pointer to the item on the top of the stack without removing it
template <class T>
T* Stack<T>::top() {
    if (topPoint < 0) {
        throw StackUnderflowException();
    }
    return stacks[topPoint];
}

// return an int that is the number of items in the stack
template <class T>
int Stack<T>::length() {
    return topPoint + 1;
}

// empty all the items in the stack
template <class T>
void Stack<T>::empty() {
    while (topPoint >= 0) {
        delete stacks[topPoint];  // free the objects
        topPoint--;
    }

    topPoint = -1;
}

// to ensure no memory leaks
template <class T>
Stack<T>::~Stack() {
    empty();
    delete[] stacks;
}

#endif
