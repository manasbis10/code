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

    if(k&1)
    {
        cout<<"No"<<endl;
        return;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int i = 0, j = n - 1;
    int sum = k;
    while (i < j && sum > 0)
    {
        int diff = 2 * (abs(arr[i] - arr[j]));
        if (sum >= diff)
        {
            sum -= diff;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
    if (sum == 0)
    {
        cout << "Yes" << endl;
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
        return;
    }
    cout << "No" << endl;
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