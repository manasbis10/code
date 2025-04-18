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
using ii = pair<int, int>;
#define F first
#define S second
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<ii> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr.push_back({a[i] + b[i], i});
    }
    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a[arr[i].S] -= 1;
            b[arr[i].S] = 0;
        }
        else
        {
            a[arr[i].S] = 0;
            b[arr[i].S] -= 1;
        }
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
        sum2 += b[i];
    }
    cout<<sum1 - sum2<<endl;
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