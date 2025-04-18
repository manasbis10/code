#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_sub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int bin_exp(int base, int exp, int m)
{
    if (exp == 0)
        return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0)
    {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) { return bin_exp(a, m - 2, m); }
/*---------------------------------------------------------------------------------------*/
int dp[3001][3001];

int solve(int l, int r, vector<int>&arr)
{
    if(l>r) return 0;
    if(l==r)
    {
        return arr[l];
    }
    if(dp[l][r] != - 1) return dp[l][r];
    int ans = 0;
    ans = max(arr[l] - solve(l+1, r, arr), arr[r] - solve(l, r-1, arr));
    return dp[l][r] = ans;
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = solve(0, n-1, arr);
    cout<<ans<<endl;

    return 0;
}