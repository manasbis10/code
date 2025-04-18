#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    map<int, int>mp;
    for(int i =0;i<n;i++) 
    {
        cin>>arr[i];
        mp[arr[i]] = INT_MAX;
    }

    vector<int>dp(n, 0);
    dp[0] = 1;
    mp[arr[0]] = 0;
    for(int i =1;i<n;i++)
    {
        dp[i] = min(dp[i-1] + 1, mp[arr[i]]);
        mp[arr[i]] = min(mp[arr[i]], dp[i-1]);
    }
    cout<<n - dp[n-1]<<endl;
    
}
int main() {
   
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
   
    
 
    return 0;
}