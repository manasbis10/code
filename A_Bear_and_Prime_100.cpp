#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

int mod = 1e9+7;
int main() {
    
    map<int, bool> primeMap;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
    43, 47};

    
    for (int prime : primes) {
        primeMap[prime] = true;
    }
   int  count = 0;
    for(auto i : primeMap)
    {
        cout<<i.first<<endl;
        fflush(stdout);
        string response ;
        cin>>response;

        if(response=="yes")
        {
            if(i.first*i.first<=100)
            {
                cout<<i.first*i.first<<endl;
                fflush(stdout);

                string res;
                cin>>res;
                if(res=="yes")
                {
                    cout<<"composite"<<endl;
                    return 0;
                }
            }
            count++;
            if(count==2)
            {
                cout<<"composite"<<endl;
                return 0;
            }
        }

    }
    cout<<"prime"<<endl;
    
    
 
    return 0;
}