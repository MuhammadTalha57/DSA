# include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    } 
}


int main() {
    int arr[10] = {76,2,9,1,32,0,32,4,9,1};
    bubbleSort(arr, 10);

    for(int i: arr) {
        cout << i << ' ';
    }

    return 0;
}