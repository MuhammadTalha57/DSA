# include <iostream>

using namespace std;

void merge(int arr[], int lo, int m, int hi) {
    int n1 = m - lo + 1;
    int n2 = hi - m;

    int* arrLow = new int[n1];
    int* arrHigh = new int[n2];

    for(int i = 0; i < n1; i++) {
        arrLow[i] = arr[lo + i];
    }

    for(int i = 0; i < n2; i++) {
        arrHigh[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = lo;
    while(i < n1 && j < n2) {
        if(arrLow[i] < arrHigh[j]) {
            arr[k++] = arrLow[i++];
        }
        else {
            arr[k++] = arrHigh[j++];
        }
    }

    while(i < n1) {
        arr[k++] = arrLow[i++];
    }

    while(j < n2) {
        arr[k++] = arrHigh[j++];
    } 



}

void mergeSort(int arr[], int lo, int hi) {
    if(lo < hi) {
        int m = (lo + hi) / 2;
        mergeSort(arr, lo, m);
        mergeSort(arr, m+1, hi);
        merge(arr, lo, m, hi);
    }
}


int main() {
    int arr[10] = {76,2,6,13,61,0,32,4,9,1};
    mergeSort(arr, 0, 9);

    for(int i: arr) {
        cout << i << ' ';
    }

    return 0;
}