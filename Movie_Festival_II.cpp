#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    multiset<int> endTimes;

    for (int i = 0; i < k; i++) {
        endTimes.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = endTimes.upper_bound(arr[i].second);
        if (it != endTimes.begin()) {
            --it;
            endTimes.erase(it);
            endTimes.insert(arr[i].first);
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
