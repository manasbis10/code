#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;
int be(int a, int p)
{
    if(p==0) return 1;

    int t = be(a, p/2);

    if(p&1)
    {
        return (((t*t)%mod)*a)%mod;
    }
    else{
        return (t*t)%mod;
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int ans = be(3, 3*n);
    int wrong = be(7, n);

    ans = (ans - wrong + mod)%mod;
    cout<<ans;
 
    return 0;
}