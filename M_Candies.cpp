#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9 + 7;

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = ((dp[i][j]) % mod + (dp[i][j - 1]) % mod) % mod;
        }

        for (int k = 0; k <= x; k++)
        {

            if (k - arr[i] > 0)
            {
                dp[i + 1][k] = ((dp[i][k]) - (dp[i][k - arr[i] - 1]) + mod) % mod;
            }
            else
                dp[i + 1][k] = dp[i][k];
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}