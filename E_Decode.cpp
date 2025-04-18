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
    string s;
    cin>>s;

    int n = s.length();
    vector<int>prefix(n+1);
    prefix[0] = 0;

    for(int i = 1;i<=n;i++)
    {
        prefix[i] = (s[i-1] == '1') ? 1 : -1;
    }
    for(int i = 1;i<=n;i++)
    {
        prefix[i] += prefix[i-1];
    }

    map<int, int>mp;
    int ans = 0;
    for(int i = 0;i<=n;i++)
    {
        int left = mp[prefix[i]];
        int r = n - i + 1;

        ans = (ans + (left*r)%mod)%mod;

        mp[prefix[i]] += i+1;

    }
    cout<<ans<<endl;




  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}