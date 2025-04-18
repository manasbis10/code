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
    string s;
    cin>>s;

    vector<int>c;

    for(int i = 0;i<n;i++)
    {
        if(s[i] == '*')
        {
            c.push_back(i);
        }
    }

    int c_size = c.size();
    int req = c_size/2;

    int sum = 0;

    for(int i = req ;i>=1;i--)
    {
        sum += c[i] - c[i-1] - 1;
        c[i-1] = c[i] - 1;
    }
    for(int i = req ;i<c_size - 1;i++)
    {
        sum += c[i+1] - c[i] - 1;
        c[i+1] = c[i] + 1;
    }
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