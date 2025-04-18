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
void solve()
{
    int n;
    cin >> n;
    vector<ii>arr;
    vector<int> l(n), r(n), c(n), diff;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    for(int i = 0;i<n;i++)
    {
        arr.push_back({l[i], 0});
        arr.push_back({r[i], 1});
    }
    sort(arr.begin(), arr.end());
    stack<ii>st;

    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i].second == 0)
        {
            st.push(arr[i]);
        }
        else
        {
            auto top = st.top();
            st.pop();
            diff.push_back(arr[i].first - top.first);

        }
    }

    sort(diff.begin(), diff.end());
    sort(c.rbegin(), c.rend());
    int ans = 0;

    for(int i = 0;i<n;i++) ans+= diff[i]*c[i];

    cout<<ans<<endl;



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