#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/
bool check1(vector<int>&arr)
{
    for(int i = 1;i<arr.size();i++)
    {
        int diff = abs(arr[i] - arr[i-1]);
        if(1<=diff && diff<=3)continue;
        else return false;
    }
    bool isInc = arr[0] < arr[1];
    for(int i = 1;i<arr.size();i++)
    {
        if(arr[i-1] < arr[i] && isInc == false)return false;
        if(arr[i-1] > arr[i] && isInc == true)return false;

    }
    return true;
}
bool check(vector<int>&arr)
{
    bool ans=  false;
    vector<int>temp = arr;
    for(int i = 0;i<arr.size();i++)
    {
        temp.erase(temp.begin() + i);
        ans = ans || check1(temp);
        temp = arr;

    }
    return ans;
}
void solve() {
    string line;
    int cnt = 0;
   while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        vector<int> sequence;
        int num;

        while (iss >> num) {
            sequence.push_back(num);
        }
        
        cnt += check(sequence);
  
    }
    cout<<cnt<<endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}