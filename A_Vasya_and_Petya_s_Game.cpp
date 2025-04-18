#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n+1,1);
    arr[0] = 0;
    arr[1] = 0;
    vector<int>ans;
    
    for(int i = 2;i<=n;i++)
    {
        if(arr[i])
        {
            for(int j = i*i;j<=n;j+=i)
            {
                arr[j] = 0;
            }
        }
        
    }

    for(int i = 2;i<=n; i++)
    {
         if(arr[i])
        {
            
            for(int j = i;j<=n;j=j*i)
            {
                ans.push_back(j);
            }
        }
        
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
   

 
    return 0;
}