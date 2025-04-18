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
void solve(int i, vector<int>&r, set<vector<int>>&s, int k, int sum, int n, vector<int>curr)
{
    if(i == n)
    {
        if(sum % k == 0 && curr.size() == n)
        {
            s.insert(curr);
            return;
        }
        else
        {
            return;
        }
    }

    for(int j = 1;j<=r[i];j++)
    {
        curr.push_back(j);
        solve(i+1, r, s, k, sum + j, n, curr);
        curr.pop_back();
    }
    

}
void solve() {
    int n, k;
    cin>>n>>k;

    vector<int>r(n);
    for(int i = 0;i<n;i++)
    {
        cin>>r[i];
    }
    set<vector<int>>s;
    vector<int>curr;

    solve(0, r, s, k, 0, n, curr);

    for(auto i : s)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}