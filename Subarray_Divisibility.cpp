
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){

    int n;
    cin>>n;

    int arr[n];
    vector<int>prefix(n);
    for(int i =0;i<n;i++) 
    {
        cin>>arr[i]; 
        prefix[i] = arr[i];
    }

    for(int i =1;i<n;i++)
    {
        prefix[i] += prefix[i-1];
    }
    map<int, int>mp;
    mp[0] = 1;
    int count = 0;
    for(int i =0;i<n;i++)
    {
        int rem = prefix[i]%n;
        rem = rem<0 ? n + rem : rem;
        if(mp.count(rem)) count+=mp[rem];

        mp[rem]++;
    }
    cout<<count<<endl;

   

    return 0;
    
}