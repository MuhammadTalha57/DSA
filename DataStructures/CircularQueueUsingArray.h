# ifndef CIRCULARQUEUEUSINGARRAY_H
# define CIRCULARQUEUEUSINGARRAY_H

# include <iostream>
# include <vector>

template <typename T> class CircularQueue {
private:
    int front;
    int rear;
    int capacity;
    std::vector<T> data;
public:
    CircularQueue(unsigned int c);

    bool isEmpty();

    bool isFull();

    void enqueue(T e);

    void dequeue();

    T getFront();

    int getSize();

    int getCapacity();
};

template <typename T>
CircularQueue<T>::CircularQueue(unsigned int c) {
    front  = -1;
    rear = -1;
    capacity = c;
    data = std::vector<T>(capacity);
}

template <typename T>
bool CircularQueue<T>::isEmpty() {
    return front == -1;
}


template <typename T>
bool CircularQueue<T>::isFull() {
    return (rear + 1) % capacity == front;
}

template <typename T>
void CircularQueue<T>::enqueue(T e) {
    if(isFull()) {
        throw std::runtime_error("Cannot enqueue, Queue Full");
    }

    else if(isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % capacity;
    data[rear] = e; 
}

template <typename T>
void CircularQueue<T>::dequeue() {
    if(isEmpty()) {
        throw std::runtime_error("Cannot dequeue, Queue is Empty");    
    }

    else if(front == rear) {
        front = -1;
        rear = -1;
    }

    else {
        front = (front + 1) % capacity;
    }
}

template <typename T>
T CircularQueue<T>::getFront() {
    if(isEmpty()) {
        throw std::runtime_error("Queue is Empty");
    }
    return data[front];
}

template <typename T>
int CircularQueue<T>::getSize() {
    if(isEmpty()) {
        return 0;
    }

    if(front <= rear) {
        return rear - front + 1;
    }
    else {
        return capacity - (front - rear) + 1;
    }
}

template <typename T>
int CircularQueue<T>::getCapacity() {
    return capacity;
}

# endif