#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/

void solve() {
    int n;
    cin>>n;

    vector<int>a(n);
    vector<int>cnt(100001);
    

    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    vector<int>dp(100001);
    dp[1] = cnt[1];

    for(int i = 2;i<=1e5;i++)
    {
        dp[i] = max(dp[i-1], cnt[i]*i + dp[i-2]);

    }   
    cout<<dp[100000]<<endl;


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}