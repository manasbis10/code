#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char>st;

    for(auto i : s)
    {
        st.insert(i);
    }

    string t = "";
    for(auto i : st) t+=i;

    map<char, char>mp;
    int i =0, j = t.length() - 1;
    
    while(i<=j)
    {
        mp[t[i]] = t[j];
        mp[t[j]] = t[i];
        i++;
        j--;
    }

    string ans = "";

    for(auto i : s)
    {
        ans+=mp[i];
    }
    cout<<ans<<endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;

    while(tc--)
    {
        solve();
    }
 
    return 0;
}