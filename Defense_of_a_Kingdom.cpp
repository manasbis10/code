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
    int w, h, n;
    cin>>w>>h>>n;

    if(n==0)
    {
        cout<<w*h<<endl;
        return;
    }

    vector<int>x, y;
    x.push_back(-1);
    y.push_back(-1);
    for(int i = 0;i<n;i++)
    {
        int u, v;
        cin>>u>>v;
        u--;v--;
         x.push_back(u);
         y.push_back(v);
    }
    x.push_back(w);
    y.push_back(h);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int len = 0, breadth = 0;
    for(int i = 0;i<x.size()-1;i++)
    {
        len = max(len, abs(x[i] - x[i+1]) - 1);
    }
     for(int i = 0;i<y.size()-1;i++)
    {
        breadth = max(breadth, abs(y[i] - y[i+1]) - 1);
    }

    cout<<len*breadth<<endl;
  

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


