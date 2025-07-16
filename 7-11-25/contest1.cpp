#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans[n];
    ans[0] = 0;

    for(int i=1; i<n; i++) {

        if(arr[i] > arr[i-1]) {
            ans[i] = i;
        }
        else {
            int j = ans[i-1]-1;
            while(j>=0) {
                if(arr[j] < arr[i])
                    break;
                j = ans[j]-1;
            }
            ans[i] = j+1;
        }
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
