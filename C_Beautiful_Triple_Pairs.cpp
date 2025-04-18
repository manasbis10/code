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
    for(int i =0;i<n;i++) cin>>arr[i];
    int ans = 0;
    map<array<int, 3>, int>mp;
    for(int i = n-1;i>=2;i--)
    {
        int a = arr[i-2], b = arr[i-1], c = arr[i];
       // cout<<a<<b<<c<<endl;
       int same = mp[{a,b,c}];

       ans += mp[{-1,b,c}] + mp[{a,-1,c}] + mp[{a,b,-1}] ;
       //cout<<mp[{-1,b,c}] + mp[{a,-1,c}] + mp[{a,b,-1}]<<endl;
       ans-= 3*same;
       mp[{a,b,c}]++;
       mp[{-1,b,c}]++;
       mp[{a,-1,c}]++;
       mp[{a,b,-1}]++;

    }

    
    cout<<ans<<endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;

    while(tc--)
    {
        solve();
    }
 
    return 0;
}