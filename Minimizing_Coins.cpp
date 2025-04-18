#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;
signed main() {
   
    int n,target ;
    cin>>n>>target;
    vector<int>arr(n);
 
    for(int i =0;i<n;i++) cin>>arr[i];
    
    vector<int>dp(1000000+1, INT_MAX);
    for(auto i : arr) dp[i] = 1;
    dp[0] = 0;
    for(int i = 1;i<=target;i++)
    {
        int mini = INT_MAX;
        for(int j = 0;j<n;j++)
        {
            if(i - arr[j]>=0)
            mini =  min(mini, dp[i - arr[j]]);
        }
        dp[i] =min(dp[i], 1 + mini);
    }
    if(dp[target]==INT_MAX)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[target];
 
    return 0;
}