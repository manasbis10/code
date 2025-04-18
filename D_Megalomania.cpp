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
bool comp(pair<int, int>&a, pair<int, int>&b)
{
    if(a.second < b.second) return true;
    else if(a.second == b.second)
    {
        return a.first<=b.first;
    }
    else return false;

}
void solve()
{
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    int time_right_now = 0;
    for(int i = 0;i<n;i++)
    {
        if(time_right_now + arr[i].first <= arr[i].second)
        {
            time_right_now += arr[i].first;
        }
        else
        {
            cout<<"No"<<endl;
            return;
        }

    }
    cout<<"Yes"<<endl;

    return;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}