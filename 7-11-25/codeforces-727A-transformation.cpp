#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> ans;
    ans.push_back(b);

    while(b > a) {
        if(b%2==0) {
            b /= 2;
            ans.insert(ans.begin(), b);
        }
        else if(b%10==1){
            b -= 1;
            b /= 10;
            ans.insert(ans.begin(), b);
        }
        else {
            break;
        }
    }

    if(b==a) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}
