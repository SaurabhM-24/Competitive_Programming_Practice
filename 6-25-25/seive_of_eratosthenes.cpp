#include <iostream>
using namespace std;

int seive_of_eratosthenes(int n) {

    int count = 0;

    int sieve[n+1];
    fill(sieve, sieve+(n+1), 1);
    sieve[0] = 0;
    sieve[1] = 0;
    
    for(int i=0; i<= n; i++) {
        if(sieve[i] == 0)
            continue;
        
        cout << i << ", ";
        count++;

        for(int j=i*i; j<=n; j+=i) {
            sieve[j] = 0;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int count = seive_of_eratosthenes(n);
    cout << "\nCount of primes = " << count;

    return 0;
}
