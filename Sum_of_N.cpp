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

int n = 1000000;
vector<int> is_prime;
vector<int>prefix;

void solve()
{
    int n;
    cin >> n;

    int sum = 0;
    

    if(is_prime[n])
    {
        cout<<prefix[n]*n<<endl;
        return;
    }
    if(n%2 == 0)
    {
        cout<<2*n<<endl;
        return;
    }
    for(int i = 2; i*i<=n;i++)
    {
        if(n % i == 0)
        {
            cout<<prefix[i]*n<<endl;
            return;
        }
    }
    
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    is_prime.assign(n + 1, 1);      // Initially assume all numbers are prime
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime numbers

    for (int i = 2; i<= n; ++i)
    {
        if (is_prime[i])
        {
            is_prime[i] = i;
            
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    prefix = is_prime;
    for(int i = 1;i<prefix.size();i++) prefix[i] += prefix[i-1];
 
    

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}