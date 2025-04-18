
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){

   int n;
   cin>>n;
   vector<vector<int>>arr;

   for(int i =0;i<n;i++)
   {
     int a, b;
     cin>>a>>b;
        arr.push_back({a,b, i});
   }
   sort(arr.begin(), arr.end());
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>pq;
    vector<pair<int ,int>>rooms;
  rooms.push_back({arr[0][2],1});
  int last_room = 1;
  pq.push({arr[0][1], arr[0][0], 1});

  for(int i = 1;i<n;i++)
  {
        int start  = arr[i][0];
        int end = arr[i][1];

        auto top = pq.top();
        if(start>top[0])
        {
            pq.pop();
            pq.push({end, start, top[2]});
            rooms.push_back({arr[i][2],top[2]});
        }
        else
        {
            pq.push({end, start, last_room+1});
            rooms.push_back({arr[i][2],last_room+1});
            last_room+=1;
        }

  }
  set<int>st;
  for(auto i : rooms) st.insert(i.second);
  cout<<st.size()<<endl;
  sort(rooms.begin(), rooms.end());
  for(auto i : rooms) cout<<i.second<<" ";


    return 0;
    
}