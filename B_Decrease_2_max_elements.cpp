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
    for(int i = 0;i<n;i++) cin>>a[i];

    priority_queue<int>pq;

    for(auto i : a) pq.push(i);

    int cnt = 0;

    while(1)
    {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();

        if(a==0 || b==0)
        {
            cout<<cnt<<endl;
            return;
        }
        cnt++;
        pq.push(a-1);
        pq.push(b-1);
    }
    return ;



}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}