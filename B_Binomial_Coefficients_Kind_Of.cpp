#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;


int mx(int base, int exponent) {
    base %= MOD;
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; 
        exponent /= 2;
    }
    return result;
}

int32_t main() {
    int testCases;
    cin >> testCases;
    vector<int> exponents(testCases);
    for (int i = 0; i < testCases; ++i) {
        cin >> exponents[i];
    }
    
    for (int i = 0; i < testCases; ++i) {
        cout << mx(2, exponents[i]) << endl;
    }

    return 0;
}
