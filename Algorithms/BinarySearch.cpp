# include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key) {
    // arr should be sorted.
    int lo = 0;
    int hi = n-1;
    int m;

    while(lo <= hi) {
        m = (lo + hi) / 2;
        if(arr[m] == key) {return m;}

        else if(arr[m] > key) {hi = m - 1;}

        else {lo = m + 1;}
    }
    return -1;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(arr, 10, 9) << endl;

    return 0;
}