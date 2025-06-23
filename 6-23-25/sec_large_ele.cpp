//find the second largest element in an array

#include <iostream>
#include <climits>
using namespace std;

int sec_large_ele(int arr[], int n) {

    int max = INT_MIN, sec_large = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > max) {
            sec_large = max;
            max = arr[i];
            continue;
        }
        else if(arr[i] < max && arr[i] > sec_large)
            sec_large = arr[i];
    }
    return sec_large;
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

    int sec_large = sec_large_ele(arr, n);
    cout << sec_large;

    return 0;
}
