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
    string s, t;
    cin>>s>>t;

    map<int, int>mp;
    for(int i = 0;i<t.length()-1;i++) mp[t[i]] = i;

    string ans = "";
    int len = 1e9, m = t.length();

    for(int i = 1; i<s.length();i++)
    {
        if(mp.count(s[i]) != 0)
        {
            if(i + (m - mp[s[i]]) < len)
            {
                ans = s.substr(0, i+1) + t.substr(mp[s[i]]+1);
                len = ans.length();
            }
        }
    }
    if(ans.empty())
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}
