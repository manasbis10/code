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
    vector<int>a(n);
    vector<int>visited(n+1,0);
    for(int i = 0;i<n;i++)
    {
        int c;
        cin>>c;
        c--;
        a[i] = c;
    }

    for(int i = 0;i<n;i++)
    {
        if(i == 0)
        {
            visited[a[i]] = 1;
            continue;
        }
        bool l = false, r= false;
        if(a[i] - 1 >=0 && visited[a[i] - 1] == 1)
        {
            
            l = true;
        }
        if(a[i] + 1 < n && visited[a[i] + 1] == 1)
        {
            
            r = true;
        }
        if(l == false && r== false)
        {
            
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            visited[a[i]] = 1;
           
        }
        
    }
    cout<<"YES"<<endl;
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