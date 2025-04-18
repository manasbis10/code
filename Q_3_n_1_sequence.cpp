#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int solve(int n, int cnt)
{
    if(n==1)
    {
        cnt++;
        return cnt;
    }
    if(n&1) return solve(3*n + 1, cnt+1);
    else return solve(n/2, cnt+1);
}

signed main() {
    int n ;
    cin>>n;
    int ans = solve(n, 0);
    cout<<ans;

    return 0;
}
