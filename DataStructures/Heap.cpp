# include <iostream>
# include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> data; 
public:

    MaxHeap(vector<int> arr) {
        data = arr;
        heapifyBuild( (data.size() / 2) - 1 );
    }

    int getParent(int i) {
        if(i == 0) {
            return -1;
        }
        else {
            return (i-1)/2;
        }
    }

    int getLeftChild(int i) {
        if(i < 0 || i >= data.size()) {
            return -1;
        }

        else {
            if( ((2*i) + 1) >= data.size() ) {
                return -1;
            }
            else {
                return (2*i) + 1;
            }
        }
    }

    int getRightChild(int i) {
        if(i < 0 || i >= data.size()) {
            return -1;
        }
        else {
            if( ((2*i) + 2) >= data.size()) {
                return -1;
            }
            else {
                return (2*i) + 2;
            }
        }
    }

    void heapifyUp(int child) {
        // For insertion, child = data.size() - 1

        if(data.size() == 0) {
            cout << "Heap empty\n\n";
            return;
        }

        int parent = getParent(child);

        while(parent != -1 && data[child] > data[parent]) {
            swap(data[parent], data[child]);
            child = parent;
            parent = getParent(child);
        }
    }

    void heapifyDown(int parent) {
        if(data.size() == 0) {
            cout << "Heap empty\n\n";
            return;
        }

        int l = getLeftChild(parent);
        int r = getRightChild(parent);
        int max = parent;

        if(l != -1) {
            if(data[l] > data[max]) {max = l;}
        }
        
        if(r != -1) {
            if(data[r] > data[max]) {max = r;}
        }

        if(max != parent) {
            swap(data[parent], data[max]);

            // After swapping parent is at max index now
            heapifyDown(max);
        }
    }

    void heapifyBuild(int parent) {
        // When calling, parent should be ( data.size() / 2 ) - 1
        // This ensures that building starts from non-leaf nodes

        if(data.size() == 0) {
            cout << "Heap empty\n\n";
            return;
        }

        while(parent >= 0) {
            heapifyDown(parent--);
        }
        

    }

    int getMax() {
        if(data.size() == 0) {
            return -1;
        }
        else {
            return data[0];
        }
    }

    void removeMax() {
        if(data.size() == 0) {
            cout << "Heap empty\n\n";
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

    void insert(int e) {
        data.push_back(e);
        heapifyUp(data.size() - 1);
    } 

};