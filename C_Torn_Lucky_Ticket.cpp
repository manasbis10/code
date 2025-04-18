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
int score(string &s)
{
    int sum = 0;
    for (auto k : s)
    {
        sum += (k - '0');
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++)
        {
            string s;
            cin>>s;
            //cout<<n<<endl;
            a[i] = s;
        }

   // for(auto i : a)cout<<i<<" ";

    vector<vector<int>> count(6, vector<int>(46));

    for (int i = 0; i < n; i++)
    {
        int len = a[i].length();
        int sum = 0;
        for (auto k : a[i])
        {
            sum += (k - '0');
        }
        count[len][sum]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        int sum = score(s);
        int n = s.length();
        ans += count[s.length()][sum];

        // left
        int removedSum = 0, r = 0;
        for (int j = s.length() - 1; j >= 1; j--)
        {
            removedSum += s[j] - '0';
            r++;
            int requiredSum = sum - 2 * removedSum;
            int requiredLen = n - 2 * r;
            if (requiredLen >= 0 && requiredSum >= 0 && ((requiredLen + n) % 2 == 0))
            {
                ans += count[requiredLen][requiredSum];
            }
        }

        // right

        removedSum = 0, r = 0;
        for (int j = 0; j < n - 1; j++)
        {
            removedSum += s[j] - '0';
            r++;
            int requiredSum = sum - 2 * removedSum;
            int requiredLen = n - 2 * r;
            if (requiredLen >= 0 && requiredSum >= 0 && ((requiredLen + n) % 2 == 0))
            {
                ans += count[requiredLen][requiredSum];
            }
        }
    }
    cout << ans << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  

   
        solve();
    

    return 0;
}