#ifndef MAXHEAP_H
#define MAXHEAP_H

# include <vector>


template <typename T> class MaxHeap {
private:
    std::vector<T> data;
public:
    MaxHeap(std::vector<T> arr);

    void heapifyUp(int child);

    void heapifyDown(int parent);

    void heapifyBuild();

    T getMax();

    void removeMax();

    void insert(T e);

    bool isEmpty();

};


// Definitions

template <typename T>
MaxHeap<T>::MaxHeap(std::vector<T> arr) {
    data = arr;
    heapifyBuild();
}

template <typename T>
void MaxHeap<T>::heapifyUp(int child) {
    // For insertion, child = data.size() - 1

    if(isEmpty()) {
        std::cout << "Heap empty\n\n";
        return;
    }

    int parent = (child - 1) / 2;

    while(parent >= 0 && data[child] > data[parent]) {
        std::swap(data[parent], data[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

template <typename T>
void MaxHeap<T>::heapifyDown(int parent) {
    if(isEmpty()) {
        std::cout << "Heap empty\n\n";
        return;
    }

    int l = (2 * parent) + 1;
    int r = (2 * parent) + 2;
    int max = parent;

    if(l < data.size() && data[l] > data[max]) {
        max = l;
    }

    if(r < data.size() && data[r] > data[max]) {
        max = r;
    }

    if(max != parent) {
        std::swap(data[parent], data[max]);
        // After swapping, Parent is at max index.
        heapifyDown(max);
    }
}

template <typename T>
void MaxHeap<T>::heapifyBuild() {

    if(isEmpty()) {
        std::cout << "Heap empty\n\n";
        return;
    }

    // Starting from non-leaf nodes
    int parent = (data.size() / 2) - 1;

    while(parent >= 0) {
        heapifyDown(parent--);
    }

}

template <typename T>
T MaxHeap<T>::getMax() {
    if(isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    else {
        return data[0];
    }
}

template <typename T>
void MaxHeap<T>::removeMax() {
    if(isEmpty()) {
        std::cout << "Heap empty\n\n";
        return;
    }

    else if(data.size() == 1) {
        data.pop_back();
    }
    else {
        int temp = data[data.size() - 1];
        data.pop_back();

        data[0] = temp;
        heapifyDown(0);
    }
}

template <typename T>
void MaxHeap<T>::insert(T e) {
    data.push_back(e);
    heapifyUp(data.size() - 1);
}

template <typename T>
bool MaxHeap<T>::isEmpty() {
    return data.size() == 0;
}

#endif