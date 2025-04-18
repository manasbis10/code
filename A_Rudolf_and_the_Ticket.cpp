
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;
    int arr1[n];
    int arr2[m];
    for(int i =0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i =0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(arr1[i]+arr2[j]<=k) count++;
        }
    }
    cout<<count<<endl;
}   

int main(){

    int n;
    cin>>n;

    while(n--)
    {
        solve();
    }
  
   

    return 0;
    
}