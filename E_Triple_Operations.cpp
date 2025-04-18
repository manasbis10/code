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
double log3(double x) {
    return log(x) / log(3);
}
vector<int>pref(200001);

void solve() {
    int l, r;
    cin>>l>>r;

    int ans = 0;
    ans += ceil(log3(l+1));

    ans += ans;

    ans += pref[r] - pref[l];
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1;i<=200000;i++)
    {
        pref[i] = ceil(log3(i+1));
    }
    for(int i = 2;i<=200000;i++)
    {
        pref[i] += pref[i-1];
    }

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}