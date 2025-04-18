#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;


signed main() {
 
    int n, k;
    cin>>n>>k;

    vector<vector<int>>dp(k+1, vector<int>(n+1, 0));

    for(int i = 1;i<=n;i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2 ;i<=k;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int p = j;p<=n;p+=j)
            {
                dp[i][j] =(dp[i][j] + dp[i-1][p])%mod;
            }
        }
    }
    int sum = 0;

    for(int i = 0;i<=n;i++)
    {
        sum = (sum + dp[k][i])%mod;
    }

    cout<<sum<<endl;
    return 0;
}