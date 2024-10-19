# ifndef DECKUSINGARRAY_H
# define DECKUSINGARRAY_H

# include <iostream>
# include <vector>

template <typename T> class Deck {
private:
    int front;
    int rear;
    int capacity;
    std::vector<T> data;
public:
    Deck(unsigned int c);

    bool isEmpty();

    bool isFull();

    void enqueueAtFront(T e);

    void enqueueAtRear(T e);

    void dequeueAtFront();

    void dequeueAtRear();

    T getFront();

    T getRear();

    int getSize();

    int getCapacity();

};

template <typename T>
Deck<T>::Deck(unsigned int c) {
    capacity = c;
    front = -1;
    rear = -1;
    data = std::vector<T>(capacity);
}

template <typename T>
bool Deck<T>::isEmpty() {
    return front == -1;
}


template <typename T>
bool Deck<T>::isFull() {
    return (rear + 1) % capacity  == front;
}


template <typename T>
void Deck<T>::enqueueAtRear(T e) {
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
void Deck<T>::enqueueAtFront(T e) {
    if(isFull()) {
        throw std::runtime_error("Cannot enqueue, Queue Full");
    }

    else if(isEmpty()) {
        front = 0;
        rear = 0;
    }
    else if(front == 0) {
        front = capacity - 1;
    }
    else {
        front = (front - 1) % capacity;
    }

    data[front] = e;
}


template <typename T>
void Deck<T>::dequeueAtFront() {
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
void Deck<T>::dequeueAtRear() {
    if(isEmpty()) {
        throw std::runtime_error("Cannot dequeue, Queue is Empty");    
    }

    else if(front == rear) {
        front = -1;
        rear = -1;
    }
    else if(rear == 0) {
        rear = capacity - 1;
    }
    else {
        rear = (rear - 1) % capacity;
    }
}

template <typename T>
T Deck<T>::getFront() {
    if(isEmpty()) {
        throw std::runtime_error("Queue is Empty");
    }
    return data[front];
}

template <typename T>
T Deck<T>::getRear() {
    if(isEmpty()) {
        throw std::runtime_error("Queue is Empty");
    }
    return data[rear];
}

template <typename T>
int Deck<T>::getSize() {
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
int Deck<T>::getCapacity() {
    return capacity;
}

# endif