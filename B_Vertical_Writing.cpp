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
bool comp(string &s, string &t)
{
    return s.length()>t.length();
}
void solve() {
  int n;
  cin>>n;
  vector<string>arr(n);
int maxi = -1;
  for(int i =0 ;i<n;i++)
  {
    cin>>arr[i];
    int len = arr[i].length();
    maxi = max(maxi, 1LL*len);
  }

  reverse(arr.begin(), arr.end());

  for(auto &i : arr)
  {
    int extra = maxi - i.length();
    while(extra--)
    {
        
        i.push_back('*');
    }
  }
 vector<string>ans;
  for(int i = 0;i<maxi;i++)
  {
    string t = "";
    for(int j = 0;j<n;j++)
    {
        t.push_back(arr[j][i]);
    }
    int j = t.length()-1;
    while(j>=0 && t[j] == '*') j--;
    ans.push_back(t.substr(0, j+1));
    
  }
  for(auto i : ans)
  {
    string p = i;
    int len = p.length();
    for(int k = 0;k<p.length();k++)
    {
        if(p[k] != '*')
        cout<<p[k];
        else if(p[k] == '*' && p[len-1] != '*')
        {
            cout<<p[k];
        }
    }
    cout<<endl;
  }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}