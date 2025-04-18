/*
Problem Name: Meet in the Middle
Problem Link: https://cses.fi/problemset/task/1628
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    string s;
    cin>>s;

    map<int, int>mp;
    for(auto i : s) mp[i-'0']++;
    int len = 0;
    for(int i =0;i<s.length();i++)
    {
        int val = s[i] - '0';
        val = 1 - val;
        if(mp[val]>0)
        {
            len++;
            mp[val]--;
        }
        else break;
    }
    cout<<s.length() - len<<endl;
}

int main(){

    int tc ;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
    
}