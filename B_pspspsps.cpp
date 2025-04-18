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
    int n;
    cin>>n;

    string s;
    cin>>s;

    

    int p = 0, st = 0, dot = 0;

    for(auto i : s)
    {
        if(i == 'p')p++;
        else if( i =='s')st++;
        else dot++;
    }
    bool flag = false;
    for(int i = 0;i<n;i++)
    {
        if(s[i] == 'p')
        {
            flag = true;
        }
        else if(s[i] == 's')
        {
            if(flag)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    
    if(st!= 0)
    {
        if(p == 1 && s[n-1] == 'p')
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    if(st ==0 || p==0)
    {
        cout<<"YES"<<endl;
            return;
    }
    if(dot == n)
    {
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;
    return;



  

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