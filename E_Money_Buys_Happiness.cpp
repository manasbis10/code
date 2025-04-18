#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;


void solve()
{
    int m, s;
    cin>>m>>s;

    vector<pair<int, int>>arr(m);
    int sum = 0;

    for(int i =0;i<m;i++)
    {
        cin>>arr[i].first>>arr[i].second;
        sum+=arr[i].second;
    }

    vector<vector<int>>dp(m, vector<int>(sum+1, 1e15));

    if(arr[0].first==0) dp[0][arr[0].second] = 0;

    for(int i = 0;i<m;i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1;i<m;i++)
    {
        for(int j = 1;j<=sum;j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j - arr[i].second>=0 &&  dp[i-1][j-arr[i].second] + arr[i].first <= i*1LL*s)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j-arr[i].second] + arr[i].first);
            }
            
        }
    }
    //cout<<dp[2][200];
    int ans = -1;

    for(int i = sum;i>=0;i--)
    {
        if(dp[m-1][i] != 1e15)
        {
            ans = i;
            break;
        }
        
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