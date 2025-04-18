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
    int n;
    cin>>n;

    set<int>zero, one;

    for(int i = 0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        if(y == 0)
        {
            zero.insert(x);
        }
        else
        {
            one.insert(x);
        }
    }
    int cnt = 0;
    for(auto i: one)
    {
        if(zero.find(i) != zero.end())
        {
            cnt += n - 2;
        }
    }
    for(auto i: one)
    {
        if(zero.find(i-1) != zero.end() && zero.find(i+1) != zero.end())
        {
            cnt++;
        }
    }
    for(auto i: zero)
    {
        if(one.find(i-1) != one.end() && one.find(i+1) != one.end())
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
  

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