#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    int n, t, k;
    cin>>n>>t>>k;

    int s = 1;
    int e = n;
    int ans = 0;
    while(s<=e)
    {
        int mid = s + (e - s)/2;
        cout<<"? "<<1<<" "<<mid<<endl;
        int response;
        cin>>response;
        if(mid - response==k)
        {
            ans = mid;
            e = mid -1;
        }
        else if(mid - response<k)
        {
            s = mid+1;
        }
        else e = mid - 1;
    }

   
   
    return 0;
}