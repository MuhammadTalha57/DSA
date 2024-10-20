# include <iostream>

using namespace std;

int partition(int arr[], int lo, int hi) {
    int pivot = arr[lo];

    int i = lo, j = hi + 1;
    while(i < j) {
        do {
            i++;
        } while (i != hi && arr[i] <= pivot);


        do {
            j--;
        } while(j != 0 && arr[j] > pivot);

        if(i < j) {
            swap(arr[i], arr[j]);
        }

    }

    swap(arr[j], arr[lo]);

    return j;


}

void quickSort(int arr[], int lo, int hi) {
    if(lo < hi) {
        int j = partition(arr, lo, hi);
        quickSort(arr, lo, j-1);
        quickSort(arr, j+1, hi);
    }
}


int main() {
    int arr[10] = {76,2,9,1,32,0,32,4,9,1};
    quickSort(arr, 0, 9);

    for(int i: arr) {
        cout << i << ' ';
    }

    return 0;
}