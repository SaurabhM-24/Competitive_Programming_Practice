#include <iostream>
using namespace std;

int max_sum_cont_subarr(int arr[], int n) {

    int max = 0;

    for(int i=0; i<n ;i++) {

        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum > max)
                max = sum;
        }
    }
    return max;
}

int kadane_algo(int arr[], int n) {
    
    int ans = arr[0];
    int sum = arr[0];

    for(int i=0; i<n; i++) {

        if(sum+ arr[i] > sum)
            sum += arr[i];
        
        if(ans < sum)
            ans = sum;
    }
    return ans;
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

    int sum = max_sum_cont_subarr(arr, n);
    cout << sum;

    return 0;
}
