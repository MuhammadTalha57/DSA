# include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    int temp, j;
    for(int i = 1; i < n; i++) {
        temp = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main() {
    int arr[10] = {76,2,9,1,32,0,32,4,9,1};
    insertionSort(arr, 10);

    for(int i: arr) {
        cout << i << ' ';
    }

    return 0;
}