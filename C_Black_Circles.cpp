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
int dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
void solve() {
  int n;
  cin>>n;

  vector<pair<int, int>>arr(n);
  for(int i =0;i<n;i++)
  {
    cin>>arr[i].first>>arr[i].second;
  }
  int xs, ys, xt, yt;
  cin>>xs>>ys>>xt>>yt;

  int shortestDist = dist(xs, ys, xt, yt);

  for(auto i : arr)
  {
    int dist2 = dist(xt, yt, i.first, i.second);

    if(dist2<=shortestDist)
    {
        cout<<"NO"<<endl;
        return;
    }
  }
  cout<<"YES"<<endl;
  return;

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