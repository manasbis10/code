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
  int n, x, y;
  cin>>n>>x>>y;

  set<int>s;
  vector<int>a(x);

  for(int i = 0;i<x;i++)
  {
    int el;
    cin>>el;
    el--;
    a[i] = el;
    s.insert(el);
  }
  sort(a.begin(), a.end());

  int ans = x - 2;

  for(auto i : a)
  {
    if(s.count((i+1)%n) == 0 && s.count((i+2)%n) == 1)
    {
        
        ans++;
    }
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