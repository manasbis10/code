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
    int n;
    cin>>n;
    vector<int>arr(n);
    set<int>s;

    for(int i =0;i<n;i++) 
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if(s.size()==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(n==2)
    {
        if(arr[0]==arr[1])
        {
            cout<<"NO"<<endl;
            return;
        }
        else{
            cout<<"YES"<<endl;
            cout<<arr[0]<<" "<<arr[1]<<endl;
            return;
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    if(arr[0]==arr[1])
    {
        swap(arr[1], arr[n-1]);
    }
    cout<<"YES"<<endl;
    for(auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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