#include <iostream>
#include <queue>
using namespace std;

bool check_child(int n, int m) {

    if(m > n)
        return false;
    
    queue<int>q;
    q.push(n);

    while(!q.empty()) {
        int el = q.front();
        q.pop();

        if(el==m)
            return true;
        
        if(el%3!=0)
            continue;
        
        q.push(el/3);
        q.push(el/3 * 2);
    }
    return false;
}

int main() {
    int t;
    cout << "Enter the number of test cases";
    cin >> t;

    int n, m;
    for(int i=0; i<t; i++) {
        cin >> n >> m;
        if(check_child(n, m))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}