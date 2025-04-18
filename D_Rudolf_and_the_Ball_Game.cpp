
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    int n, m, x;
    cin>>n>>m>>x;
    vector<int>a(n);
    a[x-1] = 1;
    for(int i =0;i<m;i++)
    {
        int d;
        char ch;
        cin>>d>>ch;
        vector<int>b(n, 0);
        
        for(int j = 0;j<n;j++)
        {
            if(a[j]==0) continue;
            if(ch=='0') b[(j+d)%n] = 1;
            if(ch=='1') b[(n+(j-d))%n] = 1;
            if(ch=='?')
            {
                b[(j+d)%n] = 1;
                b[(n+(j-d))%n] = 1;
            }
        }
        a=b;
    }
    int count = 0;
    for(auto i : a) if(i) count++;

    cout<<count<<endl;
    for(int i =0;i<n;i++)
    {
        if(a[i]) cout<<i+1<<" ";
    }
    cout<<endl;
    
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