#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

int mod = 1e9+7;
int main() {
   
    int n,target ;
    cin>>n>>target;
    int price[n], pages[n];
 
    for(int i =0;i<n;i++) cin>>price[i];
    for(int i =0;i<n;i++) cin>>pages[i];

    vector<vector<int>>dp(n, vector<int>(target +1));

    for(int i = price[0];i<=target;i++)
    {
        dp[0][i] = pages[0];
    }

    for(int i =1;i<n;i++)
    {
        for(int j = 1;j<=target;j++)
        {
            int ex = dp[i-1][j];
            int inc = INT_MIN;
            if(j - price[i]>=0)
            {
                inc = pages[i] + dp[i-1][j - price[i]];
            }
            dp[i][j] = max(inc, ex);
        }
    }

    cout<<dp[n-1][target]<<endl;
    
 
    return 0;
}