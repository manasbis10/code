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
bool check(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mp;
    for (auto i : arr)
        mp[i]++;
    int count = 0;

    for (auto i : mp)
    {
        if (i.second & 1)
            count++;
    }
    if (n & 1 && count <= 1)
        return true;
    if (n % 2 == 0 && count == 0)
        return true;
    return false;
}
void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i] % k].push_back(arr[i]/k);
    }

    if (check(arr))
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0, count_odd = 0;

    for (auto i : mp)
    {
        auto v = i.second;
        int s = v.size();
        sort(v.begin(), v.end());
        if (s & 1)
        {
            count_odd++;
            if (count_odd > 1)
            {
                cout << -1 << endl;
                return;
            }
            vector<int>pref(s), suff(s);

            for(int i = 1;i<s;i = i+2)
            {
                if(i-2>=0)
                {
                    pref[i] = pref[i-2] + ((v[i] - v[i-1]));
                }
                else pref[i] = (v[i] - v[i-1]);
            }

            for(int i = s - 2;i>=0;i = i - 2)
            {
                if(i+2<s)
                {
                    suff[i] = suff[i+2] + ((v[i+1] - v[i]));
                }
                else suff[i] = (v[i+1] - v[i]);
            }
            int mini = INT_MAX;

            for(int i = 0;i<s;i = i + 2)
            {
                int sum = 0;
                if(i-1>=0) sum += pref[i-1];
                if(i+1<s) sum += suff[i+1];

                mini = min(mini, sum);
            }
            

            ans += mini;
        }
        else
        {
            for (int j = 1; j < s; j = j + 2)
                ans += (v[j] - v[j - 1]) ;
        }
    }

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