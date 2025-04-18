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

    if(n % 2 == 0)
    {
        cout<<-1<<endl;
        return;
    }
    if(n == 1)
    {
        cout<<1<<endl;
        return;
    }

    vector<int>arr(n);

    arr[n/2] = 1;
    arr[n/2 - 1] = 2;
    arr[n/2 + 1] = 3;

    for(int i = n/2 - 2;i>=0;i--)
    {
        arr[i] = arr[i+1] + 2;
        
    }

    for(int i = n/2 + 2;i<n;i++)
    {
        arr[i] = arr[i-1] + 2;
        
    }
    for(auto i : arr)cout<<i<<" ";
  

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