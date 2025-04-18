#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++) cin>>arr[i];

    if(arr[0]==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
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