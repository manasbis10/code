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

    int i = 0, j = 0;
    int n = s.length(), m = t.length();

    while(i<n && j<m)
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        else if(s[i] != '?' && s[i] != t[j])
        {
            i++;
        }
        else if(s[i] == '?' && s[i] != t[j])
        {
            s[i] = t[j];
            i++;j++;
        }

    }
    if(j==m && i<n)
    {
        for(int k = i;k<n;k++)
        {
            if(s[k] == '?') s[k] = 'a';
        }
        cout<<"YES"<<endl;
        cout<<s<<endl;
        return;
    }

    if(i==n && j!=m)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(i==n && j==m)
    {
        cout<<"YES"<<endl;
        cout<<s<<endl;
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