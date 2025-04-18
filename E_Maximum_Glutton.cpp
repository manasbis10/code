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
  int n, x, y;
    cin >> n >> x >> y;


    vector<int>sweet(n), salty(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sweet[i];
        cin >> salty[i];
    }
    vector dp(n + 1, vector(n + 1, vector<int>(x + 1, 1e9)));

    dp[0][0][0] = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            for(int k = 0;k<=x;k++)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);

                if(k + sweet[i-1] <= x)
                {
                    dp[i][j][k+sweet[i-1]] = min(dp[i][j][k+sweet[i-1]], salty[i-1] + dp[i-1][j-1][k]);
                }
            }
        }
    }
    int ans = -1e9; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dp[n][i][j] <= y)
                ans = max(ans, i+1);
        }
    }

    cout << ans << endl;



}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}