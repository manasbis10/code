#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



void solve()
{
    int n, k;
    cin>>n>>k;

    vector<int>arr(n);

    for(int i =0;i<n;i++) cin>>arr[i];

    int i = 0, j =1;
    int count = 0, l = 0;
    for(;j<k-1;j++)
    {
        if(arr[j-1]<arr[j] && arr[j]>arr[j+1]) 
        {
            arr[j] = 1e9+7;
            count++;
        }
    }
    
    int maxi = count;
    // cout<<count;
    while(j<n-1)
    {
        i++;
        j++;

        if(arr[j-1]>arr[j-2] && arr[j-1]>arr[j])
        {
            count++;
            arr[j-1] = 1e9+7;
        }
        if(arr[i]==1e9+7) count--;

        if(count>maxi)
        {
            maxi = count;
            l = i;
        }
    }
    cout<<maxi+1<<" "<<l+1<<endl;

}

signed main() {

  int tc;
  cin>>tc;

  while(tc--)
  {
    solve();
  }
  return 0;
}