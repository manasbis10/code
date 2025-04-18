
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
void solve()
{
    int n;
    cin>>n;
    vector<vector<char>>arr(2*n, vector<char>(2*n,'.'));

    for(int i = 0;i<2*n;i=i+4)
    {
        for(int j =0;j<2*n;j=j+4)
        {
            arr[i][j] = '#';
            arr[i+1][j] = '#';
            arr[i][j+1] = '#';
            arr[i+1][j+1] = '#';
        }
    }
    for(int i = 2;i<2*n;i=i+4)
    {
        for(int j =2;j<2*n;j=j+4)
        {
            arr[i][j] = '#';
            arr[i+1][j] = '#';
            arr[i][j+1] = '#';
            arr[i+1][j+1] = '#';
        }
    }
    for(int i = 0;i<2*n;i=i+1)
    {
        for(int j =0;j<2*n;j=j+1)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    
    return 0;
    
}