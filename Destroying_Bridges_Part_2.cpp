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
    int n, c;
    cin>>n>>c;

    vector<int>arr(n);

    for(int i = 0;i<n;i++) cin>>arr[i];
    vector<int>prefix = arr;

    sort(prefix.begin(), prefix.end());
    int index = -1;
    for(int i = 0;i<n;i++)
    {
        if(arr[0] == prefix[i])
        {
            index = i;
        }
    }
    for(int i = 1;i<n;i++) prefix[i] += prefix[i-1];
    int ans = n, count = 0;


    for(int i = 0;i<n-1;i++)
    {
        if((prefix[i])*(prefix[n-1] - prefix[i]) <= c)
        {
           count++;
            
        }
    }
    
    cout<<n - count<<endl;

    

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