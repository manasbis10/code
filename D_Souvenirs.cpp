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

    int n, m;
    cin >> n >> m;
    
    vector<int>b(m), a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];
    

    int sum = 0;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int i = 0, j = 0;
    while(i<n && j<m)
    {
        if(a[i]>=b[j])
        {
            sum+= a[i];
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j != m)
    {
        cout<<-1<<endl;
        return;
    }
    
    cout<<sum<<endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}