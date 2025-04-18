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
    int a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;

    int ans = 0;

    if(a1>b1 && a2>=b2)ans++;
    if(a1>b2 && a2>=b1)ans++;
    if(a2>b1 && a1>=b2)ans++;
    if(a2>b2 && a1>=b1)ans++;

    if(a1==b1 && a2>b2)ans++;
    if(a1==b2 && a2>b1)ans++;
    if(a2==b1 && a1>b2)ans++;
    if(a2==b2 && a1>b1)ans++;


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