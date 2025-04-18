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
bool ok(int x, int sum, vector<int> &arr, int k)
{
    int n = arr.size();
    if (sum - x <= k)
        return true;
    for (int i = arr.size() - 1; i >= max(1LL, (int)arr.size() - x); i--)
    {
        sum -= arr[i];
        int rem = x - (n - i);
        int temp = sum - arr[0] + (arr[0] - rem) * (n - i + 1);
        if (temp <= k)
            return true;
    }
    return false;
}
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    int s = 0, e = 1e10;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (ok(mid, sum, arr, k))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
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
