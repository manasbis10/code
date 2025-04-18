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
    int n, k;
    cin>>n>>k;

    vector<vector<int>>arr(n, vector<int>(n));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            char ch;
            cin>>ch;
            arr[i][j] = ch - '0';
        }
    }
    vector<vector<int>>ans;

    for(int i = 0;i<n;i+=k)
    {
        vector<int>t;
        for(int j = 0;j<n;j+=k)
        {
            if(arr[i][j] == 1)
            {
                t.push_back(1);
            }
            else t.push_back(0);
        }
        ans.push_back(t);
    }
     for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[0].size();j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
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