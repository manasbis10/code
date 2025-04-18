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
    for(int i =0;i<n;i++)cin>>a[i];
    

    int t = 0;
    for(int i = 0;i<n;i++)
    {
         
        int q = a[i]/5;
        
        t += q*3;
       
        
        a[i] = a[i]%5;

        
        if(a[i] == 0)continue;
        else if(a[i] == 1)
        {
            t+=1;
        }
        else if(a[i] == 2)
        {
            
            if(t%3 == 0) t+=2;
            else if(t%3 == 1) t+=2;
            else if(t%3 == 2) t+=1;

        }
        else if(a[i] == 3)
        {
            if(t%3 == 0) t+=3;
            else if(t%3 == 1) t+=2;
            if(t%3 == 2) t+=1;

        }
        else if(a[i] == 4)
        {
            if(t%3 == 0) t+=3;
            else if(t%3 == 1) t+=2;
            if(t%3 == 2) t+=2;

        }
        
    }

    
    cout<<t<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
        solve();
    

    return 0;
}