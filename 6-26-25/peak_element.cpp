#include <iostream>
using namespace std;

int find_peak(int arr[], int start, int end) {

    if(start > end)
        return -1;
    
    int mid = start + (end-start)/2;

    if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
        return arr[mid];
    
    if(arr[mid-1] > arr[mid])
        return find_peak(arr, start, end-1);
    else
        return find_peak(arr, start+1, end);
    
    return -1;
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

    cout << find_peak(arr, 0, n-1);
    
    return 0;
}
