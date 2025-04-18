#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    int n, r;
    cin>>n>>r;

    vector<int>arr(n);

    for(int i =0;i<n;i++) cin>>arr[i];

    int count = 0;
    int i =0, j = 1;

    while(j<n)
    {
        if(arr[j] - arr[i] > r)
        {
            count+= n - j;
            i++;
        }
        else
        {
            j++;
        }
    }

    cout<<count<<endl;
  
}