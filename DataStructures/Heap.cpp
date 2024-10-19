# include <iostream>
# include <vector>
# include <queue>

using namespace std;

class Heap {
private:
    vector<int> data; 
public:

    Heap(vector<int> arr) {
        data = arr;
        heapify();
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

    void heapify(int k = -1){
        // k = 0 (Delete)   k = 1 (Insert)   else (constructing)
        if(data.size() == 0) {
            cout << "Heap empty\n\n";
            return;
        }

        if(k == 1) {
            k = data.size() - 1;
            int i = getParent(k);
            while(i != -1 && data[k] > data[i]) {
                swap(data[i], data[k]);
                k = i;
                i = getParent(k);
            }
        }

        else {

            if(k == -1) {
                k = data.size()- 1;
            }

            queue<int> q;
            q.push(k);

            while(!q.empty()) {
                int i = q.front();
                q.pop();

                int l = getLeftChild(i);
                int r = getRightChild(i);
                int max = i;

                if(l != -1) {
                    if(data[l] > data[max]) {max = l;}
                }
                
                if(r != -1) {
                    if(data[r] > data[max]) {max = r;}
                }

                if(max != i) {
                    swap(data[i], data[max]);
                    q.push(max);
                    continue;
                }

                if(k != 0) {q.push(--k);}
            }

        }
    }

    void BFS() {
        if(data.size() != 0) {
            queue<int> q;
            q.push(0);

            while(!q.empty()) {
                int i = q.front();
                q.pop();

                cout << data[i] << ' ';

                int l = getLeftChild(i);
                int r = getRightChild(i);

                if(l != -1) {q.push(l);}

                if(r != -1) {q.push(r);}
            }
            cout << endl << endl;

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
            heapify(0);
        }
    }

    vector<int> sort() {
        vector<int> temp(data.size());

        for(int i = data.size() -1; i >= 0; i--) {
            temp[i] = getMax();
            removeMax();
        }
        return temp;
    }

    void insert(int e) {
        data.push_back(e);
        heapify(1);
    } 

};


int main() {
    Heap h({5, 3, 69, 420, 4, 8, 7, 4});

    vector<int> t = h.sort();

    for(int i: t) {
        cout << i << ' ';
    }

    return 0;
}