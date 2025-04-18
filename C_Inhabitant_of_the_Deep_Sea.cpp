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

    deque<int>dq;
    for(int i =0;i<n;i++) dq.push_back(a[i]);

    while(dq.size() >1 && k>0)
    {
        int mn = min(dq.front(), dq.back());

        if(k < 2*mn)
        {
            
            dq.front() -= (k+1)/2 ;
            dq.back() -= k/2;
            k = 0; 
        }
        else
        {
            dq.front() -= mn;
            dq.back() -= mn;
            k -= 2*mn;
        }
        if(dq.front() == 0) dq.pop_front();
        if(dq.back() == 0) dq.pop_back();
    }
    int ans = n - dq.size();
    cout << ans + (dq.size() && dq.front() <= k) << '\n';

  

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