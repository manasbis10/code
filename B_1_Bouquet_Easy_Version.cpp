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
bool check(vector<int>&arr, int head, int tail, int m, int cost)
{
    if(abs(arr[head] - arr[tail]) > 1) return false;
    if(cost + arr[head] > m) return false;
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    sort(arr.begin(), arr.end());
    
    int tail = 0, head = -1, cost = 0, maxi = LLONG_MIN;
    while(tail<n)
    {
        while(head + 1<n && check(arr, head+1, tail, m, cost))
        {
            head++;
            cost += arr[head];
        }
        maxi = max(maxi, cost);
       

        if(tail<=head)
        {
            cost -= arr[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail -1;
        }

    }
    cout << maxi << endl;
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