#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int a,b;
    cin>>a>>b;

    int req = ceil(b/2.0);
    if(req==0)
    {
        int ans = ceil((a)/15.0);
        cout<<ans<<endl;
        return;
    }
    int extra = req*15 - (4*b);

    if(extra>=a)
    {
        cout<<req<<endl;
        return;
    }
    else{
        int res = ceil(abs(extra - a)/15.0);
        cout<<req + res<<endl;
    }   
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