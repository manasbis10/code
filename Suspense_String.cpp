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

    int i = 0, j = n-1;
    deque<char>ans;
    while(i<j)
    {
        if(s[i] == '0')
        {
            ans.push_front(s[i]);
        }
        else if(s[i] == '1')
        {
            ans.push_back(s[i]);

        }

        if(s[j] == '1')
        {
            ans.push_front(s[j]);
        }
        else if(s[j] == '0')
        {
            ans.push_back(s[j]);

        }
        i++;
        j--;
        //cout<<"k";


    }
    if(i==j)
    {
        if(s[i] == '0')
        {
            ans.push_front(s[i]);
        }
        else if(s[i] == '1')
        {
            ans.push_back(s[i]);

        }

    }
    
    string temp = "";
    while(!ans.empty())
    {
        auto ch = ans.front();
        ans.pop_front();
        temp +=ch;
    }
    cout<<temp<<endl;
  

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