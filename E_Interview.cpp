#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n+1);

    for(int i =1;i<=n;i++) cin>>arr[i];

    for(int i = 2;i<=n;i++) 
    {
        arr[i] = arr[i] + arr[i-1];
    }
    int s = 1;
    int e = n;
    int ans  = -1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        cout<<"? "<<mid - s + 1<<" ";
        for(int i = s;i<=mid;i++) cout<<i<<" ";
        cout<<endl;
        cout.flush();
        int sum = 0;
        cin>>sum;
        if(sum> arr[mid] - arr[s-1])
        {
            ans = mid;
            e = mid;
            if(s==e)
            {
                break;
            }
        }
        else s= mid+1;

    }
    cout<<"! "<<ans<<endl;

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