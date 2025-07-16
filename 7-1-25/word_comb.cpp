#include <iostream>
using namespace std;

int main() {

    int a, b, c, m=0;
    cin >> a >> b >> c;

    int a1 = a+b+c;
    if(a1 > m)
        m=a1;
    int a2 = a+b*c;
    if(a2 > m)
        m=a2;
    int a3 = (a+b)*c;
    if(a3 > m)
        m=a3;
    int a4 = a*b+c;
    if(a4 > m)
        m=a4;
    int a5 = a*(b+c);
    if(a5 > m)
        m=a5;
    int a6 = a*b*c;
    if(a6 > m)
        m=a6;

    cout << m;
    return 0;
}
