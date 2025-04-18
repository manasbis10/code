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
  int cnt = 0;
  for(int i = 0;i<n;i++) 
  {
    cin>>arr[i];
    if(arr[i] == 1)cnt++;
  }

  for(int i = 0;i<cnt;i++) cout<<1<<" ";
  if(n - cnt != 2)
  {
    
    sort(arr.rbegin(), arr.rend());

    for(int i = 0;i<n;i++)
    {
        if(arr[i] != 1)cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }

  if(n - cnt == 2)
  {
    sort(arr.rbegin(), arr.rend());
    if(arr[0] == 3 && arr[1] == 2)
    {
        cout<<"2 3"<<endl;
        return;
    }
    for(int i = 0;i<n;i++)
    {
        if(arr[i] != 1)cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }



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