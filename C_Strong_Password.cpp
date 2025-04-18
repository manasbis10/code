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
    string pass;
    cin>>pass;
    int m;
    cin>>m;

    string l, r;
    cin>>l>>r;

    int n = pass.size();

    map<int, vector<int>>mp;

    for(int i = 0;i<pass.size();i++)
    {
        mp[pass[i]-'0'].push_back(i);
    }
    for(int i = 0;i<=9;i++)mp[i].push_back(n);
    int ind = -1;
    for(int i = 0;i<m;i++)
    {
        int low = l[i] - '0';
        int high = r[i] - '0';
        int maxiIndex = -1;

        for(int j = low ;j<=high;j++)
        {
            auto t = upper_bound(mp[j].begin(), mp[j].end(), ind);
            if((*t) == n)
            {
                cout<<"YES"<<endl;
                return;
            }
            else{
                maxiIndex = max(maxiIndex, *t);
            }

        }
        ind = maxiIndex;
    }
    cout<<"NO"<<endl;
    return;
  

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