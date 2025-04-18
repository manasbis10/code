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
    int n, m;
    cin>>n>>m;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    string s ;
    cin>>s;

    int idx = -1;
    int i = 0, j = n-1;

    for(int k = 0;k<s.length()-1;k++)
    {
        if(s[k] == 'L')i++;
        else j--;
    }
    idx = i;
    reverse(s.begin(), s.end());

    vector<int>ans;

    int prod = arr[idx];
    i = idx, j = idx;
    ans.push_back(prod%m);

    for(int k = 1;k<s.length();k++)
    {
        if(s[k] == 'L')
        {
            i--;
            prod = (prod * arr[i])%m;
        }
        else
        {
            j++;
            prod = (prod * arr[j])%m;
        }
        ans.push_back(prod%m);
    }
    reverse(ans.begin(), ans.end());

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