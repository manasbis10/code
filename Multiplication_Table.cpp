#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
bool valid(int mid, int n)
{
    int count = 0;
    int req = (n*n)/2 + 1;
    for(int i =1;i<=n;i++)
    {
        count+= min(n, mid/i);
        if(count>=req) return true;
    }
    return false;
}

signed main() {
    int n ;
    cin>>n;
    int s = 1;
    int e = n*n;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(valid(mid, n))
        {
            ans = mid;
            e = mid-1;
        }
        else s= mid+1;
    }
    cout<<ans<<endl;

    return 0;
}
