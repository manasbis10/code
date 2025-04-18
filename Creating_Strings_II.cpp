#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

int be(int a, int p)
{
    if(p==0) return 1;

    int t = be(a, p/2);

    if(p%2==0)
    {
        return (t*t)%mod;
    }
    else{
        return (((t*t)%mod)*a)%mod;
    }
}
signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.length();
    vector<int>fact(n+1);
    vector<int>ifact(n+1);
    fact[0] = 1;

    for(int i = 1;i<=n;i++)
    {
        fact[i] = (i * fact[i-1])%mod;
    }
    //cout<<fact[3];
    ifact[n] = be(fact[n], mod-2);

    for(int i = n-1;i>=0;i--)
    {
        ifact[i] = (ifact[i+1]*(i+1))%mod;
    }
    //cout<<ifact[2]<<endl;
    vector<int>freq(26);
    for(auto i : s) freq[i-'a']++;

    int ans = fact[n];

    for(auto i : freq)
    {
        ans = (ans * ifact[i]);
    }
    cout<<ans<<endl;

 
    return 0;
}