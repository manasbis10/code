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

    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];

    set<int>first, last, s;
    map<int, int>mp;

    for(int i = 0;i<n;i++)
    {
        if(s.count(arr[i]) == 0)first.insert(i);
        s.insert(arr[i]);
        mp[arr[i]] = i;

    }
    for(auto i : mp)last.insert(i.second);

    int ans = 0;
    int cnt = 0;
    for(int i = n-1; i>=0 ;i--)
    {
        if(last.count(i) != 0)cnt++;
        if(first.count(i) != 0)ans += cnt;
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