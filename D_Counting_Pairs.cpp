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

    vector<int>a(n);
    int sum = 0;
    for(int i = 0;i<n;i++) 
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum < x)
    {
        cout<<0<<endl;
        return;
    } 
    sort(a.begin(), a.end());
    int r = sum - x;
    int l = sum - y;

    int cnt = 0;

    for(int i = 0;i<=n-2;i++)
    {
        int el = a[i];
        auto left = lower_bound(a.begin(), a.end(), l - el);
        left = max(left, a.begin() + i + 1);

        if(left == a.end()) continue;

        auto right = upper_bound(a.begin(), a.end(), r - el);
        right--;

        if(left - a.begin() > i && right - a.begin() > i && right >= left)
        cnt+= right - left + 1;
        //cout<<cnt<<endl;
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