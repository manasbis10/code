#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string>arr(n);

    for(int i = 0; i < n; i++) cin>>arr[i];

    int ans = 1;

    for(int i =0;i<m;i++)
    {
        set<char>s;
        for(int j = 0;j<n;j++)
        {
            s.insert(arr[j][i]);
        }
        ans = (ans * s.size())%mod;
    }
    cout<<ans<<endl;
 
    return 0;
}