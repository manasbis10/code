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

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    if(k>=3)
    {
        cout<<0<<endl;
        return;
    }

    sort(arr.begin(), arr.end());
    if(k == 1)
    {
        int ans = arr[0];
        for(int i = 1;i<n;i++)
        {
            ans = min(ans, abs(arr[i] - arr[i-1]));
        }
        cout<<ans<<endl;
        return;
    }
    int ans = LLONG_MAX;
    for(auto i : arr)ans = min(ans, i);
    for(int i = 0;i<n;i++)
    {
        vector<int>temp;
        for(int j = i+1;j<n;j++)
        {
            temp.push_back(abs(arr[i] - arr[j]));
        }

        for(auto p : arr)temp.push_back(p);
        sort(temp.begin(), temp.end());
        
        for(int k = 1;k<(int)temp.size();k++)
        {
            ans = min(ans, abs(temp[k] - temp[k-1]));
        }
    }
    cout<<ans<<endl;
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