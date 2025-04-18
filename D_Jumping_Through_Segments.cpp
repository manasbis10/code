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
bool check(int mid, vector<pair<int, int>> &arr)
{
    int n = arr.size();
    int x1 = 0, x2 = 0;

    for (int i = 0; i < n; i++)
    {
        int u = arr[i].first, v = arr[i].second;
        x1 = max(x1 - mid, u);
        x2 = min(x2 + mid, v);
        if(x2<x1) return false;
      
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    int start = 0, end = 1e15;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (check(mid, arr))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
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