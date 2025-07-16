#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    
    string s1, s2;
    cout << "Enter s1 and s2:\n";
    cin >> s1 >> s2;
    
    int reqd_dest = 0;
    for(char ch : s1) {
        if(ch=='+')
            reqd_dest += 1;
        else
            reqd_dest -= 1;
    }
    
    queue<int> final_dest;
    final_dest.push(0);
    
    for(char ch : s2) {
        if(ch=='+') {
            int n = final_dest.size();
            for(int i=0; i<n; i++) {
                int ele = final_dest.front();
                final_dest.pop();
                ele+=1;
                final_dest.push(ele);
            }
        }
        else if(ch=='-') {
            int n = final_dest.size();
            for(int i=0; i<n; i++) {
                int ele = final_dest.front();
                final_dest.pop();
                ele-=1;
                final_dest.push(ele);
            }
        }
        else {
            int n = final_dest.size();
            for(int i=0; i<n; i++) {
                int ele = final_dest.front();
                final_dest.pop();
                ele+=1;
                final_dest.push(ele);
                ele-=2;
                final_dest.push(ele);
            }
        }
    }
    
    double len = final_dest.size();
    double count = 0;
    while(!final_dest.empty()) {
        int e = final_dest.front();
        final_dest.pop();
        if(e==reqd_dest)
            count++;
    }
    
    double ans = count/len;
    cout << count << " " << len << " " << fixed << setprecision(12) <<  ans;

    return 0;
}