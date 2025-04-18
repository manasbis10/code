
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
vector<vector<long double>>dp;
long double solve(int i, vector<long double>&arr, int count)
{
    if(i==arr.size())
    {
        if(2*count >arr.size()) return 1;
        else return 0;
    }
    if(dp[i][count] != -1) return dp[i][count];
    long double ans = 0;

    ans = solve(i+1, arr, count+1)*(arr[i]) + solve(i+1, arr, count)*(1 - arr[i]);

    return dp[i][count] = ans;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    dp.resize(n+1, vector<long double>(n+1, -1));
    vector<long double>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    long double ans = solve(0, arr, 0);
    cout<<setprecision(10)<<ans<<endl;

    return 0;
}