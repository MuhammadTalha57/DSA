# ifndef STATICSTACK_H
# define STATICSTACK_H

# include <iostream>

template <typename T> class StaticStack {
private:
    int top;
    int size;
    int capacity;
    T* data;
public:
    StaticStack(unsigned int c);

    bool isEmpty();

    bool isFull();

    void push(T e);

    T pop();

    T peek();

    ~StaticStack();

};

template <typename T>
StaticStack<T>::StaticStack(unsigned int c) {
    capacity = c;
    size = 0;
    top = -1;
    data = new T[capacity];
}

template <typename T>
bool StaticStack<T>::isEmpty() {
    return size == 0;
}

template <typename T>
bool StaticStack<T>::isFull() {
    return size == capacity;
}

template <typename T>
void StaticStack<T>::push(T e) {
    if(isFull()) {
        std::cout << "Cannot Push, Stack Full\n\n";
        return;
    }

    data[++top] = e;
    size++;

}

template <typename T>
T StaticStack<T>::pop() {
    if(isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    T temp = data[top--];
    size--;
    return temp;
}

template <typename T>
T StaticStack<T>::peek() {
    if(isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    return data[top];
}

template <typename T>
StaticStack<T>::~StaticStack() {
    delete[] data;
}

# endif