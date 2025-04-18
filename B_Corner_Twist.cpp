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

    vector<vector<int>>a(n, vector<int>(m));
    vector<vector<int>>b(n, vector<int>(m));

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            char ch;
            cin>>ch;
            a[i][j] = ch - '0';
        }
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            char ch;
            cin>>ch;
            b[i][j] = ch - '0';
        }
    }

    vector<int>a1(m), b1(m), c1(n), d1(n);
    
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            a1[i] += a[j][i];
        }
    }
     for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            b1[i] += b[j][i];
        }
    }
     for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            c1[i] += a[i][j];
        }
    }
     for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            d1[i] += b[i][j];
        }
    }
    for(int i = 0;i<m;i++)
    {
        if((a1[i])%3 != (b1[i])%3)
        {
            cout<<"NO"<<endl;
            return;
        }
       
    }
    for(int i = 0;i<n;i++)
    {
        if((c1[i])%3 != (d1[i])%3)
        {
            cout<<"NO"<<endl;
            return;
        }
       
    }
    cout<<"YES"<<endl;
  

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