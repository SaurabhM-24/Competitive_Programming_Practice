#include <iostream>
using namespace std;

int seive_of_eratosthenes(int n) {

    int count = 0;

    int sieve[n+1];
    fill(sieve, sieve+(n+1), 0);
    sieve[0] = -1;
    sieve[1] = 1;
    
    for(int i=2; i<= n; i++) {
        if(sieve[i] != 0)
            continue;
        
        count++;
        sieve[i] = i;

        for(int j=i*i; j<=n; j+=i) {
            sieve[j] = i;
        }
    }

    cout << '\n';
    for(int i=1; i<=n; i++) {
        cout << i << " " <<sieve[i] << '\n';
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
