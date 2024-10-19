# ifndef DYNAMICSTACK_H
# define DYNAMICSTACK_H

# include <iostream>
# include <vector>

template <typename T> class DynamicStack {
private:
    int top;
    int size;
    std::vector<T> data;
public:
    DynamicStack(std::vector<T> arr = {});

    bool isEmpty();

    void push(T e);

    T pop();

    T peek();

};

template <typename T>
DynamicStack<T>::DynamicStack(std::vector<T> arr) {
    data = arr;
    size = data.size();
    top = size - 1;
}

template <typename T>
bool DynamicStack<T>::isEmpty() {
    return size == 0;
}

template <typename T>
void DynamicStack<T>::push(T e) {
    top++;
    if(top == data.size()) {
        data.push_back(e);
    }
    else{
        data[top] = e;
    }
    size++;
}

template <typename T>
T DynamicStack<T>::pop() {
    if(isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    T temp = data[top--];
    size--;
    return temp;
}

template <typename T>
T DynamicStack<T>::peek() {
    if(isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    return data[top];
}

# endif