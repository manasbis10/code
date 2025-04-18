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
    for(int i = 0;i<n;i++)cin>>arr[i];

    vector<int>bits(31, 0);

    for(auto i : arr)
    {
        for(int j = 0;j<31;j++)
        {
            if(i & (1<<j))
            {
                bits[j]++;
            }
        }
    }
    int ans = 0;
    for(auto i : arr)
    {
        int sum = 0;
        for(int j = 0;j<31;j++)
        {
            if(i & (1<<j))
            {
                sum += (n - bits[j])*(1<<j);
            }
            else
            {
                sum += (bits[j])*(1<<j);
            }
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    
   
  


   

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }

    
        
    
    

    return 0;
}

