# ifndef QUEUEUSINGARRAY_H
# define QUEUEUSINGARRAY_H

# include <iostream>
# include <vector>

template <typename T> class Queue {
private:
    int front;
    int rear;
    int capacity;
    std::vector<T> data;
public:
    Queue(unsigned int c);

    bool isFull();

    bool isEmpty();

    void enqueue(T e);

    void dequeue();

    T getFront();

    int getSize();

    int getCapacity();

};

template <typename T>
Queue<T>::Queue(unsigned int c) {
    capacity = c;
    front = rear = -1;
    data = std::vector<T>(c);
}

template <typename T>
bool Queue<T>::isFull() {
    return rear == capacity - 1;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == -1;
}

template <typename T>
void Queue<T>::enqueue(T e) {
    if(isFull()) {     
        throw std::runtime_error("Queue Full");
    }
    if(isEmpty()){
        // First element is getting inserted
        front++;
    }
    data[++rear] = e;
}

template <typename T>
void Queue<T>::dequeue() {
    if(isEmpty()) {
        throw std::runtime_error("Cannot remove, Queue Empty");
    }
    
    if(front == rear) {
        // Only 1 element, removing that element means reset the queue.
        front = rear = -1;
    }
    else {
        front++;
    }
}

template <typename T>
T Queue<T>::getFront() {
    if(isEmpty()) {
        throw std::runtime_error("Queue Empty");
    }
    else {
        return data[front];
    }
}

template <typename T>
int Queue<T>::getSize() {
    if(isEmpty()) {
        return 0;
    }

    return rear - front + 1;
}

template <typename T>
int Queue<T>::getCapacity() {
    return capacity;
}


# endif