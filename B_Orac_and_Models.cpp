#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int n ;
    cin>>n;

    vector<int>arr(n+1);

    for(int i = 1;i<=n;i++) cin>>arr[i];

    vector<int>dp(n+1, 1);

    dp[0] = 0;

   for(int i = 2;i<=n;i++)
   {
        for(int j = 1 ; j*j<=i ; j++)
        {
            if(i%j==0)
            {
                int a = j, b = i/j;
                 if((arr[j] < arr[i]))
                dp[i] = max(dp[i], 1 + dp[j] );

                if((arr[b] < arr[i]))
                dp[i] = max(dp[i], 1 + dp[b] );
            }
            if((arr[j] < arr[i]) && (i%j==0))
            dp[i] = max(dp[i], 1 + dp[j] );
        }
   } 
   int maxi = -1;
   for(auto i : dp) 
   {
    maxi = max(maxi, i);
    //cout<<i<<" ";
   }
    //cout<<endl;
    cout<<maxi<<endl;
    
}

signed main() {

    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
 
    return 0;
}