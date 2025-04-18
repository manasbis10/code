#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod2 = 998244353;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
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

void solve()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>fact(n+1);
    fact[0] = 1;
    for(int i =1;i<=n;i++)
    {
        fact[i] = mod_mul(i, fact[i-1], mod2);
    }
    int maxi = *max_element(arr.begin(), arr.end());
    int count = 0;
    int k = 0;

    for(auto i : arr)
    {
        if(i==maxi) count++;
        else if(i==maxi-1) k++;
    }
    if(count>1)
    {
        cout<<fact[n]<<endl;
        return ;
    }

    int ans = (fact[n] - (mod_mul(fact[n],mod_inv(k+1, mod2), mod2)) + mod2)%mod2;
    cout<<ans<<endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}
