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
using ii = pair<int, int>;
#define F first
#define S second 
void solve() {

    int n, m;
    cin>>n>>m;

    vector<ii>arr(n);
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[i].F = a;
    }
    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[i].S = a;
    }

    sort(arr.begin(), arr.end());

    int maxi = LLONG_MIN;

    for(int i = 0;i<n;i++)
    {
        int mul = min(m/arr[i].F, arr[i].S);
        maxi = max(maxi, mul*arr[i].F);
    }

    for(int i = 0;i<n-1;i++)
    {
        if(arr[i].F +  1 != arr[i+1].F) continue;

        int total = 0;;

        int a = min(m/arr[i].F, arr[i].S);
        total += a*arr[i].F;

        int curr = m - total;

        int b = min(curr/arr[i+1].F, arr[i+1].S);
        total += b*arr[i+1].F;

        curr = m - total;

        int extra = min({a, arr[i+1].S - b, curr});
        maxi = max(maxi, total + extra);
    }
    cout<<maxi<<endl;
  

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