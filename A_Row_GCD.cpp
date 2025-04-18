#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;


signed main() {
 
    int n, m;
    cin>>n>>m;

    vector<int>a(n), b(m);

    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<m;i++) cin>>b[i];

    int pre = 0;
    for(int i = 1;i<n;i++)
    {
        pre = gcd(pre, abs(a[i] - a[0]));
    }

    for(int i = 0;i<m;i++)
    {
        int ans = gcd(a[0] + b[i], pre);
        cout<<ans<<" ";
    }
    return 0;
}