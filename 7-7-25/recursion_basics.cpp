#include <iostream>
using namespace std;

int fib(int n) {
    if(n==0 || n==1)
        return 1;
    
    return fib(n-1)+fib(n-2);
}

/*
tabulation

*/

int fibo(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int optimum(int n, int a=0, int b=1) {
    if(n-2==0)
        return b;
    
        return optimum(n-1, b, a+b);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int ans = optimum(n);
    cout << ans;

    return 0;
}