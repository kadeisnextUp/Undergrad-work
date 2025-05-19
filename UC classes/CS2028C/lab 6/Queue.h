#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept> // for std::runtime_error
using namespace std;

// Queue exception classes
class queue_overflow : public runtime_error {
public:
    queue_overflow() : runtime_error("Queue overflow error!") {}
};

class queue_underflow : public runtime_error {
public:
    queue_underflow() : runtime_error("Queue underflow error!") {}
};

template <typename T>
class queue {
private:
    T** array;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue(int size) : capacity(size), front(0), rear(-1), count(0) {
        array = new T*[capacity];
    }

    ~queue() {
        empty();
        delete[] array;
    }

    void enqueue(T* item) {
        if (count >= capacity) {
            throw queue_overflow();
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        count++;
    }

    T* dequeue() {
        if (count == 0) {
            throw queue_underflow();
        }
        T* item = array[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    T* peek() const {
        if (count == 0) {
            throw queue_underflow();
        }
        return array[front];
    }

    int length() const {
        return count;
    }

    void empty() {
        while (count > 0) {
            delete dequeue();
        }
    }
};
#endif 