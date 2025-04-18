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
int quickHash(string s, int p, int mod)
{
    int ans = s[0] - 'a' + 1;
    for(int i = 1;i<s.length();i++)
    {
        ans = (ans*p + (s[i] - 'a' + 1))%mod;
    }
    return ans;
}

struct hasher{
    int n, _p, _mod;

    vector<int>fhash, powk;

    void init(string& s, int p, int mod)
    {
        n = s.length();
        _p = p;
        _mod = mod;

        fhash.resize(n);
        powk.resize(n);

        powk[0] = 1;
        fhash[0] = s[0] - 'a' + 1;
        for(int i = 1;i<n;i++)
        {
            fhash[i] = (p*fhash[i-1] + (s[i] - 'a' + 1))%mod;
            powk[i] = (powk[i-1]*p)%mod;
        }

    }

    int getHash(int l, int r)
    {
        if(l==0) return fhash[r];
        return (fhash[r] - (fhash[l-1]*powk[r - l +1])%_mod + _mod)%_mod;
    }
};
void solve() {
  string s, te;
  cin>>s>>te;

  int n = s.length(), m = te.length();
  if(m>n)
  {
    cout<<0<<endl;
    return;
  }

  hasher t;
  t.init(s, 39, 1000000021);
  int h = quickHash(te, 39, 1000000021);
    int cnt = 0;
  for(int i = 0;i<n - m +1;i++)
  {
    if(t.getHash(i, i + m - 1) == h)cnt++;
  }
  cout<<cnt<<endl;



}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}