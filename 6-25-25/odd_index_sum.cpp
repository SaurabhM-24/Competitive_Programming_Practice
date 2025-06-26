#include <iostream>
using namespace std;

void odd_index_sum(int arr[], int n, int q[][2], int qn) {

    int pf[n];
    fill(pf, pf+n,0);

    int sum=0;
    for(int i=0; i<n; i++) {
        if(i%2==1)
            sum += arr[i];
        
        pf[i] = sum;
    }

    for(int i=0; i<qn; i++) {
        int l = q[i][0];
        int r = q[i][1];

        if(l==0)
            cout << pf[r] << "\n";
        else
            cout << pf[r] - pf[l-1] << "\n";
    }
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

    int qn;
    cout << "Enter the number of queries: ";
    cin >> qn;

    int q[qn][2];
    for(int i=0; i<qn; i++) {
        cout << "Enter the value of L" << i << ": ";
        cin >> q[i][0];
        cout << "Enter the value of R" << i << ": ";
        cin >> q[i][1];
    }

    odd_index_sum(arr, n, q, qn);

    return 0;
}
