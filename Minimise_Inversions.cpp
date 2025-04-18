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
int cntInv(string &s)
{
    int tot = 0;
    int ones = 0;
    for (char c : s)
    {
        if (c == '1')
            ones++;
        else
            tot += ones;
    }
    return tot;
}
void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    int countOnes = 0;
    for (auto i : s)
    {
        if (i == '1')
            countOnes++;
    }

    int ans = 1e9;

    for (int i = 0; i <= k; i++)
    {
        int one = min(i, countOnes);
        int zero = min(k - i, n - countOnes);

        string st = s;
        for (int j = 0; k < n && one > 0; j++)
        {
            if (st[j] == '1')
            {
                st[j] = '0';
                one--;
            }
        }

        for (int k = n - 1; k >= 0 && zero > 0; k--)
        {
            if (st[k] == '0')
            {
                st[k] = '1';
                zero--;
            }
        }
        ans = min(ans, cntInv(st));
    }
    cout << ans << endl;
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