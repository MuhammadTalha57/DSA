# include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    int min;
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}


int main() {
    int arr[10] = {76,2,9,1,32,0,32,4,9,1};
    selectionSort(arr, 10);

    for(int i: arr) {
        cout << i << ' ';
    }

    return 0;
}