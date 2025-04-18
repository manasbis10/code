#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;
signed main() {
   
    int n ;
    cin>>n;
    vector<int>dp(1000000 +1);
    for(int i =1;i<=6;i++) dp[i]=1;
    for(int i =2;i<=n;i++)
    {
        for(int j = 1;j<=6;j++)
        {
            if(i-j>=0)
            dp[i] = (dp[i] + dp[i-j])%mod;
        }
    }
    cout<<dp[n]<<endl;




    return 0;
}