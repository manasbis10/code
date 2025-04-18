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
    int n, m, k;
    cin>>n>>m>>k;

    int arr[m];
    for(int i = 0;i<m;i++) cin>>arr[i];

    int known[k];
    set<int>s;
    for(int i = 0;i<k;i++) 
    {
        cin>>known[i];
        s.insert(known[i]);
    }

    string ans = "";

    if(n-1 > k)
    {
        while(m--)ans += '0';
        cout<<ans<<endl;
        return;
    }
    if(n == k)
    {
        while(m--)ans += '1';
        cout<<ans<<endl;
        return;
    }

    for(int i = 0;i<m;i++)
    {
        int el = arr[i];

        if(s.count(el) == 0)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }
    cout<<ans<<endl;
    return;


  

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