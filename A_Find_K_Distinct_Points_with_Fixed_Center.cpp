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
    int x, y, k;
    cin>>x>>y>>k;

        vector<pair<int, int>>arr;
        int p = 0, q = 0;
        
        for(int i = 1;i<= k/2 ;i++)
        {
            arr.push_back({i, 0});
            arr.push_back({-i, 0});
        }

        if(k&1)
        {
            arr.push_back({0,0});
            for(int i = 0;i<arr.size();i++)
            {
                arr[i].first += x;
                arr[i].second += y;
            }

            for(auto i : arr)
            {
                cout<<i.first<<" "<<i.second;
                cout<<endl;
            }
            return;
        }

        for(int i = 0;i<arr.size();i++)
            {
                arr[i].first += x;
                arr[i].second += y;
            }

        for(auto i : arr)
            {
                cout<<i.first<<" "<<i.second;
                cout<<endl;
            }
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