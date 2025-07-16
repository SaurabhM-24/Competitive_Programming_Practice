#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int week[7];
    for(int i=0; i<7; i++) {
        cin >> week[i];
    }
    
    int i=0;
    
    while(n > 0) {
        if(i==7)
            i=0;
        
        n -= week[i];
        i++;
    }
    cout << i;
    
    return 0;
}