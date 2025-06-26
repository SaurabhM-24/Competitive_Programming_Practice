#include <iostream>
using namespace std;

int special_index(int arr[], int n) {

    int prefix[n];
    int odd=0, even=0;

    for(int i=0; i<n; i++) {
        if(i%2==1) {
            prefix[i] = even;
            odd += arr[i];
        }
        else {
            prefix[i] = odd;
            even += arr[i];
        }
    }

    int suffix[n];
    odd = 0, even = 0;

    for(int i=(n-1); i>=0; i--) {
        if(i%2==1) {
            suffix[i] = even;
            odd += arr[i];
        }
        else {
            suffix[i] = odd;
            even += arr[i];
        }
    }

    int count = 0;

    for(int i=0; i<n; i++) {
        odd = 0, even = 0;

        if(i==0) {
            odd = suffix[i+1];
            even = suffix[i];
        }
        else if(i==n-1) {
            odd = prefix[i-1];
            even = prefix[i];
        }

        else {
            if(i%2==1) {
                odd = prefix[i-1] + suffix[i];
                even = prefix[i] + suffix[i+1];
            }
            else {
                odd = prefix[i] + suffix[i+1];
                even = prefix[i-1] + suffix[i];
            }
        }
        cout << i << " " << odd << " " << even << "\n";
        if(odd==even)
            count++;
    }

    return count;
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

    int count = special_index(arr, n);
    cout << count;

    return 0;
}
