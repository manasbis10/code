
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

bool comp(const array<int,3>&a, const array<int, 3>&b)
{
    if(a[0]!=b[0])
    {
        return a[0]<b[0];
    }
    else
    {
        return a[1]>b[1];
    }
}

int main(){

    int n;
    cin>>n;
  
    vector<array<int , 3>>arr(n);
    for(int i =0;i<n;i++)
    {
        arr[i][2] = i;
        int a, b;
        cin>>a>>b;
        arr[i][0] = a;
        arr[i][1] = b;
    }
    
    sort(arr.begin(), arr.end(), comp);

    vector<int>contains(n);
    vector<int>contained(n);
    int maxiR = 0;
    int miniR = INT_MAX;

    for(int i = 0;i<n;i++)
    {
        if(arr[i][1]<=maxiR)
        {
            contained[arr[i][2]] = 1;
        }
        maxiR = max(maxiR, arr[i][1]);
    }
     for(int i = n-1;i>=0;i--)
    {
        if(arr[i][1]>=miniR)
        {
            contains[arr[i][2]] = 1;
        }
        miniR = min(miniR, arr[i][1]);
    }
    
    for(auto i : contains) cout<<i<<" ";
    cout<<endl;
    for(auto i : contained) cout<<i<<" ";

    return 0;
    
}