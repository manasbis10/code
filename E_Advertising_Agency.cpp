#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9 + 7;

//int ncr[1001][1001];
vector<vector<int>>ncr;
void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int>mp;
    for(auto i : arr) mp[i]++;
    sort(arr.begin(), arr.end());

    int count = 1;
    
    for (int i = n - k; i <= n - 2; i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
        else
            break;
    }
    int el = arr[n-k];
    int ans = ncr[mp[el]][count];
    cout<<ans<<endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ncr.resize(1001, vector<int>(1001));
   // memset(ncr, 0, sizeof(ncr));

    for (int i = 0; i < 1001; i++)
        ncr[i][0] = 1;

    for (int i = 1; i < 1001; i++)
    {
        for (int j = 1; j <= i && j < 1001; j++)
        {
            ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
        }
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}