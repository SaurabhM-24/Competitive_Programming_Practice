#include <iostream>
using namespace std;

void product_except_self(int arr[], int n) {

    int ans[n];
    int left = 1;
    for(int i=0; i<n; i++) {
        ans[i] = left;
        left *= arr[i];
    }
    int right = 1;
    for(int i=n-1; i>=0; i--) {
        ans[i] *= right;
        right *= arr[i];
    }

    cout << "Output array: ";
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
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

    product_except_self(arr, n);

    return 0;
}


/* Relevant Problem Links: 
    1. https://leetcode.com/problems/product-of-array-except-self/description/
    2. https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
