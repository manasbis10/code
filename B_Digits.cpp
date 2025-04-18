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
long long fact(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
void solve() {
    int n, d;
    cin>>n>>d;

    set<int>ans;
    ans.insert(1);
    

    if(d == 5)ans.insert(5); 


    if(n > 2)ans.insert(3);
    if(n >= 3) ans.insert(7);
    if(n >= 6) ans.insert(9);

    if(d == 3 || d == 6 || d== 9) ans.insert(3);
    if(d == 7) ans.insert(7);
    if(d == 9) ans.insert(9);

    if(n < 6)
    {
        int f = fact(n);
        if((d * f) % 9 == 0)ans.insert(9);
    }

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
  

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