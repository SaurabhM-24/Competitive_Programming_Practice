// delete a number in array such that gcd is maximum

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int max_gcd(int arr[], int n) {

    int prefix_gcd[n];
    prefix_gcd[0] = arr[0];

    for(int i=1; i<n; i++) {
        prefix_gcd[i] = gcd(prefix_gcd[i-1], arr[i]);
    }

    int suffix_gcd[n];
    suffix_gcd[n-1] = arr[n-1];

    for(int i=n-2; i>=0; i--) {
        suffix_gcd[i] = gcd(suffix_gcd[i+1], arr[i]);
    }

    int gcd_max = INT_MIN;
    int gcd_max_index = -1;
    int curr_gcd;

    for(int i=0; i<n; i++) {
        if(i==0)
            curr_gcd = suffix_gcd[i+1];
        else if (i==n-1)
            curr_gcd = prefix_gcd[i-1];
        
        else
            curr_gcd = gcd(prefix_gcd[i-1], suffix_gcd[i+1]);
        
        if(curr_gcd > gcd_max) {
            gcd_max =curr_gcd;
            gcd_max_index = i;
        }        
    }

    cout << "Maximum possible GCD: " << gcd_max;
    return arr[gcd_max_index];
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

    int delete_el = max_gcd(arr, n);
    cout << "\nElement to be deleted: " << delete_el;

    return 0;
}
