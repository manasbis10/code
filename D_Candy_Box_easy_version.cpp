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

    vector<int>arr(n), freq(210000);

    for(int i  = 0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    sort(freq.rbegin(), freq.rend());
    int sum = 0;
    sum += freq[0];
    for(int i = 1;i<210000;i++)
    {
        if(freq[i] >= freq[i-1])
        {
            freq[i] = freq[i-1] - 1;
        }
        if(freq[i] <= 0) break;
        sum += freq[i];

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