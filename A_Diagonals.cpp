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
    int n, k;
    cin >> n >> k;

    if(k == 0) 
    {
        cout<<0<<endl;
        return;
    }

    int total = 2 * n - 1;

    int cnt = 0;
    k = k - n;
    if (k <= 0)
    {
        cout << 1 << endl;
        return;
    }
    cnt++;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            k -= i;
            if (k <= 0)
            {
                cnt++;
                cout<<cnt<<endl;
                return;
            }
            else cnt++;
        }
    }
    cout << -1 << endl;
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