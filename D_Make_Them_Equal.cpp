#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9 + 7;

vector<int> req;


void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> b(n), c(n);

    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int>w(n);

    for(int i = 0;i<n;i++)
    {
        w[i] = req[b[i]];
    }
    int mx = min(k, 12*n);
    vector<vector<int>>dp(n+1, vector<int>(mx+1));

    for(int i = 1;i<=n;i++)
    {
        for(int j = 0; j<=mx;j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j - w[i-1]>=0)
            {
                dp[i][j] = max(dp[i][j], c[i-1] + dp[i-1][j-w[i-1]]);
            }
        }
    }

    int ans = dp[n][mx];
    cout<<ans<<endl;

    
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    req.resize(1001, 1001);
    req[1] = 0;

    for (int i = 1 ;i < 1001; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int el = i + i / j;
            if (el < 1001)
                req[el] = min(req[el], req[i] + 1);
        }
    }
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}