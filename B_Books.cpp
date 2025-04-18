#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;
signed main() {
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i =0;i<n;i++) cin>>arr[i];

    int maxi = 0;

    int i = 0;
    int j = 0;
    int sum = 0;
    while(j<n)
    {
        sum+=arr[j];

        if(sum>k)
        {
            sum-= arr[i];
            i++;
        }
        maxi = max(maxi,j -i +1);
        j++;
    }
    cout<<maxi<<endl;




    return 0;
}