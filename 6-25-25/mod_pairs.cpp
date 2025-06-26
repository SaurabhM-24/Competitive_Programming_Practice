#include <iostream>
using namespace std;

int brute_force(int arr[], int n, int m) {

    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; i<n; i++) {
            if((arr[i] + arr[j])%m == 0)
                count++;
        }
    }
    return count;
}

int efficient(int arr[], int n, int m) {

    int rem_count[m] = {0};
    for(int i=0; i<n; i++) {
        int rem = arr[i]%m;
        rem_count[rem] += 1;
    }

    int pairs = 0;

    for(int i=0; i<=(m/2); i++) {

        if(i==0 || (m%2==0 && i==m/2)) {
            pairs += (rem_count[0] * (rem_count[0]-1)) / 2;
        }
        else{
            pairs += (rem_count[i] * rem_count[m-i]);
        }
    }
    return pairs;
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

    int m;
    cout << "Enter the value of m: ";
    cin >> m;

    int pair = efficient(arr, n, m);

    cout << pair;
}
