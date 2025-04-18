#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    if(n==2)
    {
        
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<1<<endl;
        return;
        
    }
    
    for(int i = 1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    
    for(int i = (n/2) + 1;i<=n;i++) cout<<i<<" ";
    for(int i = 1;i<=(n/2);i++) cout<<i<<" ";
    cout<<endl;
    

}

int main() {
    // your code goes here
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }


}