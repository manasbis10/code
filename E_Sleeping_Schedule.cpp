#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9 + 7;

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INT_MIN));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            dp[i][j] = max(dp[i - 1][(j - a[i - 1] + h) % h], dp[i - 1][(j - a[i - 1] + 1 + h) % h]);
            if (j >= l && j <= r && dp[i][j] != INT_MIN)
            {
                dp[i][j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0;i<=h;i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;

    return 0;
}