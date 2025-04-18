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
  string s;
  cin>>s;
    int count = 0;
  string msg = "hello";

  stack<char>st;
  reverse(s.begin(), s.end());

  for(auto i : s) st.push(i);

  for(auto i : msg)
  {

    while(!st.empty() && st.top() != i)
    {
        st.pop();
    }
    if(!st.empty())
    {
        st.pop();
        count++;
    }
  }
  //cout<<count<<endl;
  if(count == 5)
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

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}