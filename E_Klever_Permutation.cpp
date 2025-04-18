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

  vector<int>arr(n);
  int l = 1, r = n;

  for(int i = 0 ;i<k ;i++)
  {
    for(int j = i;j<n;j += k)
    {
        if(j&1)
        {
            arr[j] = r;
            r-=1;
        }
        else
        {
            arr[j] = l;
            l +=1 ;
        }
    }
  }
  for(auto i : arr) cout<<i<<" ";
  cout<<endl;

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