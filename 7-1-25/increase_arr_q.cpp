#include <iostream>
using namespace std;

int func(int arr[], int n, int a, int b) {

    int temp[b-a+1];
    temp[0] = arr[a-1];

    int count;

    for(int i=1; i<b-a+1; i++) {
        temp[i] = arr[i+a-1];
        if(temp[i] < temp[i-1]) {
            count += temp[i-1]-temp[i];
            temp[i] += temp[i-1]-temp[i];
        }
    }
    return count;
}

int main() {
    int n, q;
    cin >> n >> q;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int a, b, count;
    for(int i=0; i<q; i++) {
        cin >> a >> b;
        if(a>=b)
            count = 0;
        else
            count = func(arr, n, a, b);
        cout << count << "\n";
    }

    return 0;
}
