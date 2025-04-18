#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++) cin>>arr[i];

    map<int, int>mp;
    for(auto i : arr) mp[i]++;
    if(mp.size()>2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(mp.size()==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(n&1)
    {
        vector<int>t;
        for(auto i : mp)
        {
            t.push_back(i.second) ;
        }
        if(t[0]+1==t[1] || t[1]+1==t[0])
        {
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    else
    {
        vector<int>t;
        for(auto i : mp)
        {
            t.push_back(i.second) ;
        }
        if(t[0]==t[1])
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
   
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}