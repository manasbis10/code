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
    int n, k;
    cin>>n>>k;
    if(n==1)
    {
        if(k==0 || k==1) 
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    vector<int>arr(n, 0);

    int i = 1, j= 3;
    while(i<n)
    {
        arr[i] = 1;
        i = i+j;
        j++;
    }

    int count = 0;
    set<int>s;
    int sum = 0;
    for(int i = 0;i<n-1;i++)
    {
        if(arr[i]==0) sum++;
        else{
            s.insert(sum);
            sum = 0;
            count++;
        }
        
    }
    if(arr[n-1]==1) count++;
    else{
        sum++;
        if(s.find(sum) == s.end()) count++;
    }
   //cout<<count<<endl;
    //for(auto i : arr) cout<<i<<" ";
    if(k<=count)
    {
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }

  

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
