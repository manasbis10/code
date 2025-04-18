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
    int n, x, y;
    cin>>n>>x>>y;

    vector<int>sweet(n), salty(n);
    for(int i = 0;i<n;i++)cin>>sweet[i];
    for(int i = 0;i<n;i++)cin>>salty[i];

    vector<pair<int, int>>arr;

    for(int i =0;i<n;i++)
    {
        arr.push_back({abs(sweet[i] - salty[i]), i});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(x - sweet[arr[i].second]>=0 && y - salty[arr[i].second]>=0)
        {
            cnt++;
            x -=sweet[i];
            y -=salty[i];
        }
        
    }

    cout<<cnt<<endl;

   
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}