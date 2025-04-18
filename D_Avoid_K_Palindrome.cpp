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
  
  int n, k;
  cin>>n>>k;

  string s;
  cin>>s;




}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<mod_sub(bin_exp(2, 40, 998244353) , mod_mul(bin_exp(2, 37, 998244353), 34, 998244353), 998244353);

        solve();
    

    return 0;
}