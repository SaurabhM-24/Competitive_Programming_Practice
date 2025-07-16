#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long calc_total(int m, int n, vector<long long>& cost_y, vector<long long>& cost_x) {
    
    sort(cost_y.rbegin(), cost_y.rend());
    sort(cost_x.rbegin(), cost_x.rend());

    long long piece_x = 1, piece_y = 1;
    int i = 0, j = 0;
    long long total = 0;

    while(i < cost_y.size() && j < cost_x.size()) {
        if(cost_y[i] >= cost_x[j]) {
            total = (total + (cost_y[i] * piece_x) % MOD) % MOD;
            piece_y += 1;
            i++;
        }
        else {
            total = (total + (cost_x[j] * piece_y) % MOD) % MOD;
            piece_x += 1;
            j++;
        }
    }

    while(i < cost_y.size()) {
        total = (total + (cost_y[i] * piece_x) % MOD) % MOD;
        piece_y += 1;
        i++;
    }
    
    while(j < cost_x.size()) {
        total = (total + (cost_x[j] * piece_y) % MOD) % MOD;
        piece_x += 1;
        j++;
    }

    return total;
}

int main() {

    int q;
    cin >> q;

    for(int i=0; i<q; i++) {
        int m, n;
        cin >> m >> n;
        
        vector<long long> cost_y(m-1);
        for(int i=0; i<m-1; i++) {
            cin >> cost_y[i];
        }

        vector<long long> cost_x(n-1);
        for(int i=0; i<n-1; i++) {
            cin >> cost_x[i];
        }

        long long total = calc_total(m-1, n-1, cost_y, cost_x);
        cout << total << '\n';
    }

    return 0;
}
