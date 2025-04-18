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
    int h, a;
    cin>>h>>a;

    int choice = 0;

    int ans  = 0;
    while(h>0 && a>0)
    {
        if(choice == 0)
        {
            h += 3;
            a += 2;
            choice = !choice;
            ans++;
        }
        else
        {
            
            if(h > 5 && a > 10)
            {
                h -= 5;
                a -= 10;
                choice = !choice;
                ans++;
            }
            else if(h > 20)
            {
                h -= 20;
                a += 5;
                choice = !choice;
                ans++;
            }
            else
            break;
        }
    }
    cout<<ans<<endl;
  

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