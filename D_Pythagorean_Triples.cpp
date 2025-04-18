#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;
vector<int>pre;

void solve()
{
    int n;
    cin>>n;
    int index = upper_bound(pre.begin(), pre.end(), n) - pre.begin();
    cout<<index<<endl;
}
signed main() {
   
    for(int i = 3;i<1e5;i+=2)
    {
        int A = i*i;
        int c = (A + 1)/2;
        pre.push_back(c);
    }
    int n;
    cin>>n;

    while(n--)
    {
        solve();
    }
 
    return 0;
}