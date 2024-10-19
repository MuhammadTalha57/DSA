# ifndef DYNAMICARRAY_H
# define DYNAMICARRAY_H

# include <iostream>

template <typename T> class DynamicArray {
private:
    int size;
    int capacity;
    T* data;
public:
    DynamicArray(unsigned int c = 0);

    bool isEmpty();

    bool isFull();

    int getSize();

    int getCapacity();

    void shrinkArray();

    void growArray();

    void insertAt(int i, T e);

    T deleteAt(int i);

    void append(T e);

    T& operator [] (int i);

    const T& operator [] (int i) const;

    T pop(int i = -1);

};


template <typename T>
DynamicArray<T>::DynamicArray(unsigned int c) {
    capacity = c;
    size = 0;
    data = new T[capacity];
}

template <typename T>
bool DynamicArray<T>::isEmpty() {
   return size == 0;
}


template <typename T>
bool DynamicArray<T>::isFull() {
    return size == capacity;
}


template <typename T>
int DynamicArray<T>::getSize() {
    return size;
}

template <typename T>
int DynamicArray<T>::getCapacity() {
    return capacity;
}

template <typename T>
void DynamicArray<T>::shrinkArray() {
    capacity = size;
    T* temp = new T[capacity];

    for(int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;

    data = temp;
}

template <typename T>
void DynamicArray<T>::growArray() {
    capacity = capacity * 2;
    T* temp = new T[capacity];
    for(int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;

    data = temp;
}

template <typename T>
void DynamicArray<T>::insertAt(int i, T e) {
    if(size == capacity) {
        growArray();
    }

    if(i != size) {
        for (int j = size; j >= i-1; j--) {
            data[j] = data[j-1]; 
        }
    }

    data[i] = e;
    size++;
}

template <typename T>
T DynamicArray<T>::deleteAt(int i) {
    if(size == 0) {
        throw std::runtime_error("Cannot remove from empty array");
    }
    if(i < 0 || i >= size) {
        throw std::runtime_error("Index out of renge");
    }

    T temp = data[i];

    for(int j = i; j < size - 1; j++) {
        data[j] = data[j + 1];
    }

    size--;
    if(size == (capacity / 2)) {
        shrinkArray();
    }

    return temp;
}

template <typename T>
void DynamicArray<T>::append(T e) {
    insertAt(size, e);
}

template <typename T>
T& DynamicArray<T>::operator[](int i) {
    if(i < 0 || i >= size) {
        throw std::runtime_error("Index out of range");
    }
    
    return data[i];
}

template <typename T>
const T& DynamicArray<T>::operator[](int i) const {
    if(i < 0 || i >= size) {
        throw std::runtime_error("Index out of range");
    }

    return data[i];
}

template <typename T>
T DynamicArray<T>::pop(int i) {
    if(i == -1) {
        return deleteAt(size - 1 );
    }
    else {
        return deleteAt(i);
    }
}



# endif