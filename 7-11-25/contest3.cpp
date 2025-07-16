#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][3];

    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    queue<int>q;
    int count = 0;

    for(int i=0; i<n; i++) {

        if(arr[i][1] != -1) {
            q.push(arr[i][1]);

            while(!q.empty()) {
                int ele = q.front()-1;
                q.pop();
                if(arr[ele][0] > arr[i][0]) {
                    count++;
                }
                if(arr[ele][1] != -1)
                    q.push(arr[ele][1]);
                if(arr[ele][2] != -1)
                    q.push(arr[ele][2]);
            }
        }
        if(arr[i][2] != -1) {
            q.push(arr[i][2]);

            while(!q.empty()) {
                int ele = q.front()-1;
                q.pop();
                if(arr[ele][0]-1 < arr[i][0]) {
                    count++;
                }
                if(arr[ele][1] != -1)
                    q.push(arr[ele][1]);
                if(arr[ele][2] != -1)
                    q.push(arr[ele][2]);
            }
        }
    }
    cout << count;

    return 0;
}
