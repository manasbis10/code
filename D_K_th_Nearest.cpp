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

    vector<int>a(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());

    while(q--)
    {
        int b, k;
        cin>>b>>k;

        int start = 0, end = 2e8 + 10, ans = -1;

        auto check = [&](int mid)
        {
            int l = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int r = upper_bound(a.begin(), a.end(), b + mid)- a.begin();

            return r - l >= k;
        };

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(check(mid))
            {
                ans = mid;
                end = mid -1;
            }
            else start = mid + 1;
        }
        cout<<ans<<endl;
    }
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}