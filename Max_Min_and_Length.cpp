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

    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());

    map<int, int>pref, suff;
    for(int i = 0;i<n;i++)
    {
        if(pref.find(arr[i] - 1) != pref.end())
        {
            pref[arr[i]] = pref[arr[i] - 1] + 1;
        }
        else pref[arr[i]] = 1;
    }   

    for(int i = n-1; i>=0; i--)
    {
        if(suff.find(arr[i] + 1) != suff.end())
        {
            suff[arr[i]] = suff[arr[i] + 1] + 1;
        }
        else suff[arr[i]] = 1;
    } 

    int cnt = 0;

    for(int i = 0;i<n;i++)
    {
        cnt += pref[arr[i]] * suff[arr[i] + 2];
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