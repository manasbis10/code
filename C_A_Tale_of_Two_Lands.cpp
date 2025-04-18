#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long


signed main() {
    int n ;
    cin>>n;
    
    vector<int>arr(n);

    for(int i =0;i<n;i++) 
    {
        int a;
        cin>>a;
        arr[i] = abs(a);
    }
    sort(arr.begin(), arr.end());
    int sum =0;
    for(int i =0;i<n-1;i++)
    {
        int el =  2*arr[i];
        auto it = lower_bound(arr.begin(), arr.end(), el);

        if(it!=arr.end())
        {
            if(el==arr[it - arr.begin()])
            {
                sum+=(it - arr.begin()) - i;
            }
            else
            sum+= (it - arr.begin()) - 1 - i;
        }
        else
        {
            sum+=n-1 - i;
        }
    }
    cout<<sum<<endl;



    return 0;
}