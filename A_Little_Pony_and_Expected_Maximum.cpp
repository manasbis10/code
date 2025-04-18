#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double m,n ;
    cin>>m>>n;

    double ans = m;
    for(int i = m-1;i>=1;i--)
    {
        double t = pow(i/m, n);
        ans = ans - t;
    }
    cout<<setprecision(12)<<ans<<endl;
 
    return 0;
}