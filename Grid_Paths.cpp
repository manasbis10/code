#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;
signed main() {
   
    int n;
    cin>>n;
    vector<vector<char>>arr(n, vector<char>(n));

    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(arr[0][0]=='*')
    {
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>>dp(n, vector<int>(n));
    dp[0][0] = 1;

    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(arr[i][j]=='*') dp[i][j] = 0;
            else{

                if(i-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(j-1>=0) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
            
        }
    }

    cout<<dp[n-1][n-1];



    return 0;
}