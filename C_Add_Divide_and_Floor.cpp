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
    vector<int>arr(n);

    

    for(int i = 0;i<n;i++) cin>>arr[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    vector<int>t;

    while(arr[0] != arr[n-1])
    {
        if(arr[0] & 1)
        {
            arr[0] = (arr[0] + 1)/2;
            arr[n-1] = (arr[n-1] + 1)/2;
            t.push_back(1);
        }
        else
        {
            arr[0] = (arr[0])/2;
            arr[n-1] = (arr[n-1])/2;
            t.push_back(0);

        }
    }
    cout<<t.size()<<endl;

    if(t.size() <=n)
    for(auto i : t) cout<<i<<" ";
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