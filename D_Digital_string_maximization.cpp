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

    string s;
    cin>>s;
    vector<int>a;
    for(auto i : s)
    {
        a.push_back(i - '0');
    }

    for(int i = 1;i<a.size() ;i++)
    {
        int j = i;
        while(j>=1 && a[j]>0 && a[j]-1 > a[j-1])
        {
            swap(a[j], a[j-1]);
            a[j-1]--;
            j--;
        }
    }
    string ans = "";
    for(auto i : a)ans+=to_string(i);
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