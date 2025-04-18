#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/
vector<int>p;
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1;
     i <= n; ++i) {
        if (!is_prime[i]) primes.push_back(i);
    }
    return primes;
}
vector<int>check(int target,  vector<pair<int, int>>&a)
{
    int i = 0;
    int j = a.size() - 1;

    while(i<j)
    {
        if(a[i].first + a[j].first == target)
        {
            return {1, a[i].second, a[j].second};
        }
        else if(a[i].first + a[j].first>target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {0, 0, 0};
}
void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    
     
    for(int i = 0;i<n;i++) 
    {
        cin>>arr[i]; 
        
    }
    vector<pair<int, int>>a;
    for(int i = 0;i<n;i++) 
    {
        a.push_back({arr[i], i});   
    }

    sort(a.begin(), a.end());

    for(auto i : p)
    {
        
        auto solve = check(i, a);
        if(solve[0] == 1)
        {
            cout<<solve[1] + 1<<" "<<solve[2] + 1<<endl;
            return;
        }
    }

    cout<<-1<<endl;


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p = sieve(202);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}