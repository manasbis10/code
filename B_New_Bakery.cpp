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
    int n, a, b;
    cin>>n>>a>>b;

    if(a>=b)
    {
        cout<<n*a<<endl;
        return;
    }
    if(b - a>=n)
    {
        int sum = 0;
        sum += (n*(2*(b - n + 1) + n - 1))/2;
        cout<<sum<<endl;
        return;
    }
    int sum = 0;
    int a_num = n - (b - a);
    sum += a_num*a;

    int b_num = b-a;
    sum += (b_num*(2*(b - b_num + 1) + b_num - 1))/2;
 
    

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