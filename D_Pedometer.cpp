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

    vector<int>arr, temp;
    int total = 0;
    
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
        total += arr[i];
    }
    // temp = arr;
    // for(int i = 0;i<n;i++)
    // {
    //     temp.push_back(arr[i]);
    // }

    map<int, int>mp;
    mp[0] = 1;
    int sum = 0, ans = 0;

    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
        int rem = sum%m;
        int revSum = total - sum; 
        int rem1 = revSum%m;
        if(mp.find(rem) != mp.end())
        {
            ans += mp[rem];
        }
        if(mp.find(rem1) != mp.end())
        {
            ans += mp[rem1];
        }
        mp[rem]++;
        mp[rem1]++;
    }
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}