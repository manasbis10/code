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

    vector<int>a(n), b(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];

    int start = 0, end = n;

    for(int i = 0;i<n;i++)
    {
        if(a[i] != b[i])
        {
            start = i;
            break;
        }
    }

    for(int i = n-1;i>=0;i--)
    {
        if(a[i] != b[i])
        {
            end = i;
            break;
        }
    }
    while(start > 0)
    {
        if(a[start-1] == b[start - 1] && b[start - 1]<=b[start])
        {
            start--;
        }
        else break;
    }
     while(end < n-1)
    {
        if(a[end+1] == b[end + 1] && b[end]<=b[end+1])
        {
            end++;
        }
        else break;
    }

    cout<<start + 1<<" "<<end+ 1<<endl;
  

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