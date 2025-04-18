#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{

    int n;
    cin>>n;

    vector<int>arr(n);
    
    for(int i =0;i<n;i++)
    {
        
        cin>>arr[i];
       
    }

    vector<int>freq(n+1);
    for(int i = 0; i<n;i++)
    {
        if(arr[i]<=n)
        freq[arr[i]]++;
    }

    vector<int>temp(n+1);
    for(int i = 1; i<=n;i++)
    {
        for(int j = i; j<=n; j+=i)
        {
            temp[j] += freq[i];
        }
    }

    int ans = INT_MIN;

    for(int i = 1;i<temp.size(); i++) 
    {
        if(i<=n)
        ans = max(ans, temp[i]);
        
    }

    cout<<ans<<endl;
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