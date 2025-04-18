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



signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    cin>>n;

    vector<int>arr(n);

    for(int i =0;i<n;i++) 
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i = n-1;i>=0;i--)
    {
        for(int j = 0;j<n;j++)
        {
            if(i>j) continue;
            if(i==j)
            {
                dp[i][j] = arr[i];
                continue;
            }
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
            
        }
    }
    cout<<(dp[0][n-1] + sum)/2; 

    return 0;
}