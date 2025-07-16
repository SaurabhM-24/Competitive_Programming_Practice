#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int x, a, b;
    for(int i=0; i<n; i++) {
        cin >> x >> a >> b;
        if(x!=1) {
            if(x-a-b == 2)
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
        else {
            if(a==1 && b==1)
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
    }
}


#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int x, a, b;
    for(int i=0; i<n; i++) {
        cin >> x >> a >> b;
        if(a+b+2 < x)
            cout << "Yes";
        else {
            if(a==1 && b==1 && x==1)
                cout << "Yes";
            else
                cout << "No";
        }
    }
}
