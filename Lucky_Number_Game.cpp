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
    int n, b, a;
    cin >> n >> b >> a;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int bob = 0, alice = 0;

    int g = gcd(b, a);

    int lcm = (a * b) / g;
    int lcm_count = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] % a == 0 && arr[i] % b == 0) {
            lcm_count++;
        }
        else if(arr[i] % b == 0) {
            bob++;
        }
        else if(arr[i] % a == 0) {
            alice++;
        }
    }
 
    // bob = bob - lcm_count;
    // alice = alice - lcm_count;
    //cout<<alice<<" "<<bob<<" "<<lcm_count;

   
        
     
        
        if (bob > alice)
        {
            cout << "BOB" << endl;
            return;
        }
        else
        {
            cout << "ALICE" << endl;
            return;
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