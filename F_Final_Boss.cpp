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

    int h, n;
    cin >> h >> n;

    int count = 1;
    int sum = 0;
    vector<int> a(n), c(n);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        pq.push({c[i], a[i], i});
    }
    h = h - sum;
    if(h<=0)
    {
        cout<<count<<endl;
        return;
    }
    
    int last_time = 0;
    while(h>0)
    {
        auto top = pq.top();
        pq.pop();
        int attack = top[1];
        int cooldown = top[0];
        int index = top[2];
        count+=cooldown - last_time;
        last_time = cooldown;
        h = h - attack;
        pq.push({cooldown + c[index], attack, index});



    }
    cout<<count<<endl;
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
