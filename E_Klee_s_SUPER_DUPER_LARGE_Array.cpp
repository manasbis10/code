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
int check(int i, int n, int k ){
    
        int l = k+n-1;
        int t = ((n)*(k+l))/2;
        int le = i-k+1;
        int te = ((le)*(k+i))/2;

        return abs(t-(2*te));
}
void solve() {
    int n, k;
    cin>>n>>k;

    if(n==2)
    {
        cout<<1<<endl;
        return;
    }
    
    int start = k, end = k + n - 1, ans = LLONG_MAX;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        
        if(check(mid, n, k) > check(mid + 1, n, k))
        {
            ans = check(mid+1, n, k);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
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