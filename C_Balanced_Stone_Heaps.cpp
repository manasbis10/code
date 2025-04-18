#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;

bool ok(int el, vector<int>&arr, int n, vector<int>h)
{
    for(int i = n-1;i>=2;i--)
    {
        if(arr[i]<el) return false;
        else{
            int req = min(h[i]/3, (arr[i] - el)/3);
            arr[i] = arr[i] - req*3;

            arr[i-1]+=req;
            arr[i-2]+= 2*req;
        }
    }
    if(arr[0]<el || arr[1]<el) return false;
    
    return true;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n), h(n);
   
    for(int i =0;i<n;i++)
    {
         cin>>arr[i];
         h[i] = arr[i];
         
    }

    int s = 1;
    int e = 1e9;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e - s)/2;

        if(ok(mid, arr, n, h))
        {
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    
    cout<<ans<<endl;
    
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