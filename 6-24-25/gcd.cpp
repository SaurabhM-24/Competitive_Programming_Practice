#include <iostream>
using namespace std;

// basic underlying idea is that gcd of a and b also divides remainder of a/b;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int a;
    cout  << "Enter a number: ";
    cin >> a;

    int b;
    cout << "Enter another number: ";
    cin >> b;

    int gc = gcd(a, b);
    cout << "GCD = " << gc;

    return 0;
}
