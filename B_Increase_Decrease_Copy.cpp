#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
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

    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n + 1; i++)
        cin >> b[i];

    int count = 1;
    for(int i = 0;i<n;i++)
    {
        count+= abs(a[i] - b[i]);
    }
    int last = b[n];
    bool isBetween = false;
    for(int i = 0;i<n;i++)
    {
        int low = min(a[i], b[i]);
        int high = max(a[i], b[i]);
        if(low<=last && last<=high) isBetween = true;

    }
    if(isBetween)
    {
        cout<<count<<endl;
        return;
    }

    int add = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        add = min({add, abs(a[i]-last), abs(b[i]-last)});
    }
    count+=add;
    cout<<count<<endl;
    return;
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
