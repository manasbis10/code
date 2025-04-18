#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9 + 7;

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j])
                count++;
        }
        ans += (1 << count) + (1 << (m - count)) - 2;
    }
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i])
                count++;
        }
        ans += (1 << count) + (1 << (n - count)) - 2;
    }

    ans = ans - (m * n);
    cout << ans << endl;

    return 0;
}