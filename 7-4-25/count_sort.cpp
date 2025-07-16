#include <iostream>
using namespace std;

void counting_sort(int arr[], int n) {

    int max=0;
    for(int i=0; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int result[max+1];
    fill(result, result+max+1, 0);

    for(int i=0; i<n; i++) {
        result[arr[i]] += 1;
    }

    int x = 0;

    for(int i=0; i<max+1; i++) {
        if(result[i] > 0) {
            for(int j=0; j<result[i]; j++) {
                arr[x] = i;
                x++;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    counting_sort(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
