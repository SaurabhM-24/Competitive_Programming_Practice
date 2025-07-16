#include <iostream>
#include <map>
using namespace std;

int count_palin(string s, int l, int r) {

    map<char, int> m;

    for(int i=l-1; i<r; i++) {
        m[s[i]] += 1;
    }

    long long int count=0;

    for(auto i : m) {
        if(i.second % 2==1)
            count+=1;
    }

    if(count==0) {
        count = m.size();
    }

    int a = count%(1000000000+7);

    return a;
}

int main() {
    string s;
    cin >> s;

    int n, l, r;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        int ans = count_palin(s, l, r);
        cout << ans << "\n";
    }

    return 0;
}
