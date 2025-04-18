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
    int t, s, n;
    cin>>t>>s>>n;

    vector<pair<int, int>>arr;

    for(int i = 0;i<t;i++)
    {
        int u, v;
        cin>>u>>v;
        arr.push_back({u,v});
        
    }
    sort(arr.begin(), arr.end());
    int c = 0;
    int maxi = 0;
    if(arr[0].first - 0>=s)
    {
        cout<<"YES"<<endl;
        return;
    }
    for(int i = 0;i<arr.size()-1;i++)
    {
        maxi = max(maxi, abs(arr[i].second - arr[i+1].first));
    }
    maxi = max(maxi,n - arr[t-1].second);
    
    if(maxi>=s)
    {
        cout<<"YES"<<endl;
        return;
    }
    else cout<<"NO"<<endl;



  

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