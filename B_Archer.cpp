#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    double f = (double)a/b;
    double r = (double)((b-a)*(d-c))/(b*d);

    double ans = (double)f/(1-r);
    cout<<setprecision(7)<<ans<<endl;
    return 0;
}