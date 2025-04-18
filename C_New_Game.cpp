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
bool check(int idx,  vector<int>&arr, int k, int tail)
{
    if(idx == 0) return true;
    if(idx - tail + 1 == 1) return true;
    if(idx - tail + 1 <= k && arr[idx] - arr[idx- 1] <= 1) return true;
    return false;
}
void solve() {
  int n, k;
  cin>>n>>k;

  map<int ,int>mp;
  vector<int>arr;
  for(int i = 0;i<n;i++)
  {
    int el;
    cin>>el;
    mp[el]++;
  }
  for(auto i : mp)arr.push_back(i.first);

  int maxi = 0;

  int tail = 0, head = -1, sum = 0;
  int k1 = arr.size();

  while(tail<k1)
  {
    while(head + 1< k1 && check(head + 1, arr, k, tail))
    {
        head++;
        sum += mp[arr[head]];
        
    }
    maxi = max(sum, maxi);
    if(tail <= head)
    {
        sum -= mp[arr[tail]];
        tail++;
    }
    else
    {
        tail++;
        head = tail - 1;
    }
  }
  cout<<maxi<<endl;

  

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