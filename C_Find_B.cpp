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
    int n, q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    vector<int>pref(n), one(n);
    if(arr[0] == 1) one[0] = 1;
    pref[0] = arr[0];
    for(int i = 1;i<n;i++)
    {
        pref[i] += pref[i-1] + arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        one[i] += one[i-1] + (arr[i] == 1);
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;
        l--;r--;
        if(l==r)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int sum = pref[r] -  (l-1>=0 ? pref[l-1] : 0);  
        int ones = one[r] -  (l-1>=0 ? one[l-1] : 0); 
        
        if(r - l + 1 + ones <= sum)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            cout<<"NO"<<endl;
        }
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