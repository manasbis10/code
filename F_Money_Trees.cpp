#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int n, k;
    cin>>n>>k;

    vector<int>cost(n), h(n);

    for(int i =0;i<n;i++) cin>>cost[i];
    for(int i =0;i<n;i++) cin>>h[i];

    int sum = 0;
    int maxi = 0;

    int i =0, j = 0;

    while(j<n)
    {
        if(sum>k)
        {
            while(sum>k)
            {
                sum-=cost[i];
                i++;
            }
        }
        if(j==0 || (h[j-1] % h[j]==0))
        {
            sum+=cost[j];   
        }
        else
        {
            i = j;
            sum = cost[j];
        }

        if(sum<=k)  maxi = max(maxi, j-i+1);

        j++;

    }
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