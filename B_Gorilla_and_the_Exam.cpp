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
    int n, k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    map<int, int>mp;

    for(auto i : arr)mp[i]++;

    vector<int>temp;
    for(auto i : mp)temp.push_back(i.second);
    int s = temp.size();
    sort(temp.begin(), temp.end());

    int i = 0;
    while(k>0)
    {
        if(k >= temp[i])
        {
            k -= temp[i];
        }
        else break;
        i++;
    }
    int ans = max(s - i, 1LL);
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