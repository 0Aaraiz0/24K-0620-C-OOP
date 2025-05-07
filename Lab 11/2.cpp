#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {
};

class QueueUnderflowException : public exception {
};

template<typename T>
class Queue {
    T data[10]; 
    int front, rear, size;
public:
    Queue() : front(0), rear(0), size(0) {}

    void enqueue(T item) {
        if (size == 10) {
            throw QueueOverflowException();
        }
        data[rear] = item;
        rear = (rear + 1) % 10;
        size++;
    }

    T dequeue() {
        if (size == 0) {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % 10;
        size--;
        return item;
    }
};

int main() {
    Queue<int> q;

    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        for (int i = 0; i < 11; ++i) {
            q.enqueue(i);  
        }
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    for (int i = 0; i < 10; ++i) {
        q.dequeue();
    }

    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();  
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
