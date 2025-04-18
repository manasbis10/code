
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
vector<int>temp;
bool isBinaryDecimal(int n) {
    string str = to_string(n);
    for (char c : str) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;

    if(isBinaryDecimal(n))
    {
        cout<<"YES"<<endl;
        return;
    }
    
    while(n!=1)
    {   
        for(int i =0;i<temp.size();i++)
        {
            if(n%temp[i]==0)
            {
                n = n/temp[i];
                break;
            }
            if(i==temp.size()-1 && n%temp[i]!=0)
            {
                cout<<"NO"<<endl;
                return;
            }

        }
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    else 
    {
        cout<<"NO"<<endl;
        return;
    }
    
}
int main(){
    
    for(int i =2;i<=1e5;i++)
    {
        if(isBinaryDecimal(i)) temp.push_back(i);
    }
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    
    return 0;
    
}