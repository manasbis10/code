#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //memset(dp, -1, sizeof(dp));

   int n;
   cin>>n;
   vector<int>a(n), b(n);

   for(int i =0;i<n;i++) cin>>a[i];

   for(int i =0;i<n;i++) cin>>b[i];

   int mx = 3000;

   vector<vector<int>>dp(n+1, vector<int>(mx+1, 0));
   dp[0][0] = 1;

   //for(int i = 1;i<mx;i++) dp[0][i] = 1;

   for(int i = 0;i<=n;i++)
   {
        for(int j = 1;j<=mx;j++)
        {
            dp[i][j] =(dp[i][j] + dp[i][j-1])%998244353;
        }

        if(i!=n)
        {
             for(int k = a[i]; k<=b[i]; k++)
            {
                dp[i+1][k] = (dp[i+1][k] + dp[i][k])%998244353;
            }
        }
       
   }

//    int ans = solve(0, a, b, -1);
   cout<<dp[n][mx]<<endl;
 
    return 0;
}