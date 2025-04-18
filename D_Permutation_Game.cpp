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
int solve(vector<int>&p, vector<int>&score, int k, int pos)
{
    int maxi = 0, curr = 0;
    int n = p.size();
    vector<int>visited(n, 0);

    int i = pos;
    while(visited[i] == 0 && k>0)
    {
        visited[i] = 1;
        maxi = max(maxi, curr + k*score[i]);
        k--;
        curr += score[i];
        i = p[i];
    }
    return maxi;
}
void solve() {
    int n, k, b, s;
    cin>>n>>k>>b>>s;
    b--;
    s--;

    vector<int>p(n), score(n);
    for(int i =0 ;i<n;i++) 
    {
        int a;
        cin>>a;
        a--;
        p[i] = a;
    }
    for(int i =0 ;i<n;i++) cin>>score[i];

    int sum1 = solve(p, score, k, b);
    int sum2 = solve(p, score, k, s);

    if(sum1 > sum2)
    {
        cout<<"Bodya"<<endl;
    }
    else if(sum1 < sum2)
    {
        cout<<"Sasha"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
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