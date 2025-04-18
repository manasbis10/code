
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int mp = 0;
    int magpie = 0;
    int p = 0;
    for(int i =0;i<n;i++)
    {
        if(s.substr(i, 5)=="mapie") magpie++;
    }
    for(int i =0;i<n;i++)
    {
        string st = s.substr(i, 3);
        if(st=="map") mp++;
        if(st=="pie") p++;
    }
    if(magpie==0)
    {
        cout<<mp + p<<endl;
        return;
    }
    else{
        mp -= magpie ;
        p -= magpie ;
        cout<<mp + p + magpie<<endl;
        return;
    }
    
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