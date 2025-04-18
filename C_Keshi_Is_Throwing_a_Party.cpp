#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;
bool solve(int el, vector<pair<int , int>>&arr)
{
    int n = arr.size();
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        int a = arr[i].first;
        int b = arr[i].second;

        if(b>=cnt && el - cnt - 1<=a) cnt++;
    }
    return cnt>=el;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<int , int>>arr(n);

    for(int i =0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;

        arr[i] = {a,b};
    }
    int s = 0;
    int e = n;
    int ans = -1;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(solve(mid, arr))
        {
            ans = mid;
            s = mid +1;
        }
        else e = mid -1;
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