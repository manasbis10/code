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
    int n, c, d;
    cin>>n>>c>>d;

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
   
    map<int, int>mp;
    for(auto i : arr) mp[i]++;
    int cnt = 0;
    vector<int>b;

    for(auto i : mp)
    {
        if(i.second > 1)cnt += i.second - 1;
        b.push_back(i.first);
    }
    
    int ans = 0;
    ans += cnt*c;
    int res = 1e18;
    int m = b.size();
    for(int i = 0;i<b.size();i++)
    {
        int cost = (b[i] - i - 1)*d + (m - i - 1)*c;
        
        res = min(res, cost);
       

    }
    cout<<min(ans + res, n*c + d)<<endl;
    
  

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