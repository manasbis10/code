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
  int n, m;
  cin>>n>>m;

  unordered_map<int, set<int>>mp;
    vector<pair<int, int>>arr;
    set<pair<int, int>>white;
  for(int i = 0;i<m;i++)
  {
    int a, b;
    cin>>a>>b;
    char ch;
    cin>>ch;

    if(ch == 'W')
    {
       
        white.insert({a, b});
    }
    else
    {
        arr.push_back({a,b});
    }

  }

  for(auto i : arr)
  {
    int r = i.first;
    int c = i.second;

   auto it = white.upper_bound({r,c});
   if(it == white.begin())
   {
        continue;
   }
   else
   {
        it--;
        cout<<(*it).first<<r<<" "<<c<<" "<<endl;
        cout<<"No"<<endl;
        return;
   }
  }
  cout<<"Yes"<<endl;
  return;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}