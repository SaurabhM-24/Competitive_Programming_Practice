// You are given an array of size n, find the numbers of pairs (i, j) such that i<j and 
// LCM(arr[i], arr[j]) > max(arr[i], arr[j]) * 10

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {

    int g = gcd(a, b);
    return ((a/g)*b);
}

int brute_force(int arr[], int n) {

    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {

            if(i < j) {
                int l = lcm(arr[i], arr[j]);
                int num = max(arr[i], arr[j]) * 10;
                if(l > num)
                    count++;
            }
        }
    }
    return count;
}

int optimized(int arr[], int n) {

    sort(arr, arr+n);

    int count = 0;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] / gcd(arr[i], arr[j]) > 10)
                count++;
        }
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
}
