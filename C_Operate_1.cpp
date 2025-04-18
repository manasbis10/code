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

    int k;
    cin>>k;
    string s, t;
    cin>>s>>t;

    if(s.length() == t.length())
    {
        int cnt = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] != t[i])cnt++;
        }

        if(cnt <= 1)
        {
            cout<<"Yes"<<endl;
            return;
        }
    }

    if(s.length() < t.length())
    {
        swap(s, t);
    }

    int i = 0, j = 0;

    while(i<s.length() && j<t.length())
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if(j==t.length() && (s.length() - t.length()) <= 1)
    {
        cout<<"Yes"<<endl;
        return;
    }

    cout<<"No"<<endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
  

    return 0;
}