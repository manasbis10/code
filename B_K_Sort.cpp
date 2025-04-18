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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;
    int maxi = arr[0];
    vector<int> diff;
    for (int i = 1; i < n; i++)
    {
        if (maxi > arr[i])
        {
            diff.push_back(abs(maxi - arr[i]));
        }
        maxi = max(maxi, arr[i]);
    }

    sort(diff.begin(), diff.end());
    int k = diff.size();
    for(int i = 0;i<k;i++)
    {
        if(i-1>=0)
        cnt += (diff[i] - diff[i-1])*(k-i+1);
        else
        cnt+= diff[i]*(k+1);

    }
    
    cout << cnt << endl;
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