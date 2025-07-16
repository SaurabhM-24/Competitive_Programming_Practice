#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    map<int, int>m;
    int ans[n-k+1];

    for(int i=0; i<k; i++) {
        m[arr[i]] += 1;
    }
    ans[0] = m.size();
    int x = 1;

    for(int i=k; i<n; i++) {
        m[arr[i-k]] -= 1;
        if (m[arr[i-k]]==0)
            m.erase(arr[i-k]);
        
        m[arr[i]] += 1;
        ans[x] = m.size();
        x++;

    }

    for(int i=0; i<n-k+1; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
