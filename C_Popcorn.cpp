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

    vector<int>arr;
    int target = (1LL<<m) - 1;
    for(int i = 0;i<n;i++)
    {
        string s;
        cin>>s;
        int el = 0;
        for(int i = 0;i<m;i++)
        {
            if(s[i] == 'o')
            {
                el = el | (1LL<<(i));
            }

        }
        arr.push_back(el);
        if(el == target)
        {
            cout<<1<<endl;
            return;
        }

    }
    sort(arr.begin(), arr.end());
   // for(auto i : arr)cout<<i<<" ";
    
    int ans = LLONG_MAX;
    
    for(int i = 0;i<(1<<n);i++)
    {
        int sum = 0, c=0;
        for(int j = 0;j<n;j++)
        {
            if(i & (1<<j))
            {
                sum = sum | arr[j];
                c++;

            }
        }
        if(sum==target)
        {
            ans = min(ans, c);

        }
    }
    
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}