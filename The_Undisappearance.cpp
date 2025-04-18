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
// Function to count subarrays with exactly K distinct elements
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> count;
    int left = 0, right = 0;
    int distinct_count = 0, result = 0;
    
    while (right < n) {
        if (count[nums[right]] == 0) {
            distinct_count++;
        }
        count[nums[right]]++;
        right++;
        
        while (distinct_count > k) {
            count[nums[left]]--;
            if (count[nums[left]] == 0) {
                distinct_count--;
            }
            left++;
        }
        
        result += right - left;
    }
    
    return result;
}

int subarraysWithAtLeastKDistinct(vector<int>& nums, int k) {
    return subarraysWithKDistinct(nums, k) - subarraysWithKDistinct(nums, k - 1);
}
void solve() {
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];

    int ans = subarraysWithAtLeastKDistinct(a, 3);
    cout<<ans<<endl;


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}