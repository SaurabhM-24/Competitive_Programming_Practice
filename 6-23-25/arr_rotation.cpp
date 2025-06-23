// rotate an array by k steps

#include <iostream>
using namespace std;

void arr_reverse(int arr[], int start, int end) {

    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void arr_rotate(int arr[], int n, int k) {

    k = k%n;
    if(k==0)
        return;
    
    arr_reverse(arr, 0, n-1);
    arr_reverse(arr, 0, k-1);
    arr_reverse(arr, k, n-1);
}

int main() {
    
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    arr_rotate(arr, n, k);

    cout << "Rotated array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
