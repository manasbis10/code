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
vector<bool> isPrime;
vector<int> primes;

void sieveOfEratosthenes(int limit, std::vector<bool>& isPrime) {
    isPrime.assign(limit + 1, true);  // Initialize all entries as true
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;
    if(n==8)
    {
        cout<<"Yes"<<endl;
        return;
    }
    n = n - 4;
    int i  = 1, j = primes.size() - 1;

    while(i<j)
    {
        int a = primes[i], b = primes[j];
        if(a*a + b*b > n)
        {
            j--;
        }
        else if(a*a + b*b == n)
        {   //cout<<a<<" "<<b;
            cout<<"Yes"<<endl;
            return;
            
        }
        else{
            i++;
        }
    }
    cout<<"No"<<endl;
    return;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int limit = 100001;  // 1e5
    sieveOfEratosthenes(limit, isPrime);

    
    for (int number = 2; number <= limit; ++number) {
        if (isPrime[number]) {
            primes.push_back(number);
        }
    }
    
    
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
