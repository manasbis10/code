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
    int zero = 0, nonzero = 0;
    for(int i = 0;i<n;i++)
    {
         cin>>arr[i];
         if(arr[i] == 0)zero++;
         else nonzero++;
    }
    if(zero == n)
    {
        cout<<0<<endl;
        return;
    }
    if(zero == 0)
    {
        cout<<1<<endl;
        return;
    }
    int index = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] != 0)
        {
            index = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = index ;i<n;i++)
    {
        if(arr[i] == 0)
        break;
        else cnt++;
    }
    if(cnt == nonzero)
    {
        cout<<1<<endl;
        return;
    }


    

    cout<<2<<endl;
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