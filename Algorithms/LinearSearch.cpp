# include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[5] = {8,2,6,1,3};
    cout << linearSearch(arr, 5, 3);

    return 0;
}