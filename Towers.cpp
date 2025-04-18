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

  vector<int>arr(n);
  for(int i =0;i<n;i++) cin>>arr[i];

  multiset<int>s;

  for(int i = 0;i<n;i++)
  {
    if(s.empty())
    {
        s.insert(arr[i]);
        continue;
    }
    auto it = s.upper_bound(arr[i]);

    if(it == s.end())
    {
        s.insert(arr[i]);
    }
    else
    {
        s.erase(it);
        s.insert(arr[i]);
    }

  }
  cout<<s.size()<<endl;


}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}