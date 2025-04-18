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
int N;
int res(int n, int k)
{
    if(n<k) return 0;
    int ans = 0;

    if(n & 1)
    {
        int a = (n/2) + 1;
        int freq = N/n, d= n+1;
        int sum = (freq *(2*a + (freq - 1)*d))/2;

        ans = sum + res(n/2, k);

    }
    else
    {
        ans = res(n/2, k);
    }
    return ans;
}
void solve() {
    int n, k;
    cin>>n>>k;
    N = n;

    int ans = res(n, k);
    cout<<ans<<endl;
  

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
