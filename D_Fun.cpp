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

void solve() {
  int n, x;
  cin>>n>>x;

  
  int count = 0;

  for (int a = 1; a <=n; ++a) {
        for (int b = 1; a*b <=n ; ++b) {
            int start = 1, end = x - (a+b);
            int ans = 0;
            while(start <= end)
            {
                int mid = start + (end- start)/2;

                if(a*b + b*mid + mid*a <= n)
                {
                    ans = mid;
                    start = mid + 1;
                }
                else end = mid -1;
            }
            count += ans;
          
        }
    }
  cout<<count<<endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}