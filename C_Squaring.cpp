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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0, last = 0;
    for (int i = 1; i < n; i++)
    {
        int c1 = 0, c2 = 0;

        int a = arr[i - 1], b = arr[i];

        if (b == 1 && a > 1)
        {
            cout << -1 << endl;
            return;
        }

        while (b < a)
        {
            c1++;
            b *= b;
        }

        while (a * a <= b)
        {
            if (a == 1)
            {
                c2 = -1;
                break;
            }
            a *= a;
            c2++;
        }
        if (c1)
            last += c1;
        else if (c2 == -1)
            last = 0;
        else
            last = max(0LL, last - c2);
        ans += last;
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