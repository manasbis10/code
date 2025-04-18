#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

int be(int a, int n, int m)
{
    if(n==0) return 1;
    int t = be(a , n/2, m);

    if(n&1)
    {
        return (((t*t)%m)*a)%m;
    }
    else 
    {
        return (t*t)%m;
    }
}
void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    int x = be(b,c, mod - 1);
    int ans = be(a, x, mod);

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