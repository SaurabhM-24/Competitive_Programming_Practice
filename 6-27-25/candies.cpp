#include <iostream>
using namespace std;

int count_candy(int arr[], int n) {

    int count_arr[n];
    fill(count_arr, count_arr+n, 1);

    for(int i=1; i<n; i++) {
        
        if(arr[i] > arr[i-1])
            count_arr[i] = count_arr[i-1] + 1;
    }

    for(int i=n-2; i>=0; i--) {
        
        if(arr[i] > arr[i+1] )
            count_arr[i] = max(count_arr[i+1]+1, count_arr[i]);
    
    }

    int sum = 0;
    for(int i : count_arr) {
        sum += i;
    }

    return sum;
}

int main() {

    int n = 6;

    int arr[] = {4, 4, 5, 4, 4, 4};

    int c = count_candy(arr, n);
    cout << "Count: " << c;

    return 0;
}
