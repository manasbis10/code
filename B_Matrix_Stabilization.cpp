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
int check(vector<vector<int>>& arr, int i, int j)
{
    int n = arr.size(), m = arr[0].size();
    int maxi = INT_MIN;
    if(i-1>=0)
    {
        maxi = max(maxi, arr[i-1][j]);
    }
    if(i+1<n)
    {
        maxi = max(maxi, arr[i+1][j]);
    }
    if(j-1>=0)
    {
        maxi = max(maxi, arr[i][j-1]);
    }
    if(j+1<m)
    {
        maxi = max(maxi, arr[i][j+1]);
    }
    if(arr[i][j] > maxi) return maxi;
    else return 0;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> arr1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    arr1 = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = check(arr, i, j); 
            if(t>0)
            {
                arr1[i][j] = t;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }


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