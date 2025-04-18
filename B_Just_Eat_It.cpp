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
    int sum = 0;
    bool p = true;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= 0)
            p = false;
        sum += arr[i];
    }

    if (p == true)
    {
        cout << "YES" << endl;
        return;
    }

    int maxiSum = 0, maxCount = 0;
    int s = 0, c = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];

       if(s==sum && i != n-1)c = 1;
       if(s == 0) z = 1;

        if (s > maxiSum)
        {
            maxiSum = s;
        }
        if (s < 0)
        {
            s = 0;
          
        }
    }
   // cout<<z<<c;

    if (maxiSum > sum)
    {
        cout << "NO" << endl;
        return;
    }
    else if (maxiSum == sum)
    {
        if (c || z)
        {
            
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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