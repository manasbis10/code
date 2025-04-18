#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>> n>>k;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];

    vector<array<int, 2>>dp((1<<n), {INT_MAX, INT_MAX});
    dp[0] = {1, 0};

    for(int i = 1;i<(1<<n);i++)
    {
        for(int bit = 0;bit<n;bit++)
        {
            if(i&(1<<bit))
            {
                int room = dp[i^(1<<bit)][1];
                if(room + arr[bit]<=k)
                {
                    dp[i] = min(dp[i], {dp[i^(1<<bit)][0], room + arr[bit]});
                }
                else
                {
                    dp[i] = min(dp[i], {dp[i^(1<<bit)][0] + 1, arr[bit]});
                }
            }
            
        }
    }
    cout<<dp[(1<<n)-1][0]<<endl;
}