#include<bits/stdc++.h>
using namespace std;
#define int long long
int solve(int& n, vector<int>&v, int target,  vector<int>&dp)
{   
    if(target<0) return 0;
    if(target == 0) return 1;
    if(dp[target] != -1 ) return dp[target];
    int ans = 0;
 
    for(int i = 0;i<n;i++)
    {
        
        ans =((ans)%1000000007 + (solve(n, v, target - v[i], dp))%1000000007)%1000000007;
    }
    return dp[target] = ans;
}
 
signed main()
{
    int n, k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>dp(k+1, -1);
    int ans = solve(n,v, k, dp);
    cout<<ans<<endl;
    return 0;
}