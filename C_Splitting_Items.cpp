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

    vector<int>a(n);
    for(int i =0;i<n;i++) cin>>a[i];

    int sum = 0;
    sort(a.rbegin(), a.rend());
    int i = 0, j = 1;
    while(j<n && i<n)
    {
        int diff = a[i] - a[j];
        if(diff <= k)
        {
            sum += 0;
            k -= diff;
        }
        else
        {
            sum += diff - k;
            k = 0;
        }
        i += 2;
        j += 2;
    }
    if(i<n)
    sum += a[i];

    cout<<sum<<endl;
  

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