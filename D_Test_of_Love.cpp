#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_sub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int bin_exp(int base, int exp, int m)
{
    if (exp == 0)
        return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0)
    {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) { return bin_exp(a, m - 2, m); }
/*---------------------------------------------------------------------------------------*/

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    s = 'L' + s;
    s = s + 'L';

    vector<int> dp(n + 2, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        if (s[i] == 'C')
        {
            for (int j = 1; j < m; j++)
            {

                if (i - j >= 0 && s[i - j] == 'L')
                    dp[i] = min(dp[i], dp[i - j]);
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (i - j >= 0 && s[i - j] == 'C') continue;
                if (i - j >= 0 && s[i - j] == 'L')
                    dp[i] = min(dp[i], dp[i - j]);
                if (i - j >= 0 && s[i - j] == 'W')
                    dp[i] = min(dp[i], j + dp[i - j]);
            }
        }

        if (dp[i] == 1e9)
        {
            cout << "NO" << endl;
            return;
        }
    }

    // for (auto i : dp)
    //     cout << i << " ";
    // cout << endl;
    if (dp[n + 1] <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}