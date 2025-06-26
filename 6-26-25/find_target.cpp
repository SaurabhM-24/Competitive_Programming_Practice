// You are given a rotated array and a target. Find the index of the target.

#include <iostream>
using namespace std;

int find(int arr[], int target, int end, int start=0) {

    if(end < start)
        return -1;
    
    int mid = start + (end-start)/2;
    if(arr[mid]==target)
        return mid;
    
    if(arr[start] <= arr[mid]) {

        if(arr[start] <= target && target <= arr[mid])
            return find(arr, target, mid-1, start);
        else
            return find(arr, target, end, mid+1);
    }
    else {

        if(arr[mid] <= target && target <= arr[end])
            return find(arr, target, end, mid+1);
        else
            return find(arr, target, mid-1, start);
    }

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

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    cout << find(arr, target, n-1, 0);

    return 0;
}
