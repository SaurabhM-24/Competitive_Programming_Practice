//Remove duplicates from a sorted array

#include <iostream>
using namespace std;

int remove_dup_size(int arr[], int n) {

    int i=0, j;
    
    for(j=0; j<n; j++) {
        if(arr[j]==arr[i]) {
            continue;
        }
        else {
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i+1;
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

    int min_size = remove_dup_size(arr, n);

    cout << "Sorted array: ";
    for(int x=0; x<min_size; x++) {
        cout << arr[x] << " ";
    }
    cout << "\n";

    cout << "Size: " << min_size;

    return 0;
}
