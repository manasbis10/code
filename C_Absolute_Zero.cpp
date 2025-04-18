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
    int even = 0, odd = 0;
    for(int i = 0;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]&1)odd++;
        else even++;
    }
    if(odd>=1 && even>=1)
    {
        cout<<-1<<endl;
        return;
    }
   
    vector<int>ans;

    for(int i = 29;i>=0;i--)
    {
        ans.push_back(1<<i);
    }

    if(even>=1) ans.push_back(1);
    cout<<ans.size()<<endl;

    for(auto i : ans) cout<<i<<" ";




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