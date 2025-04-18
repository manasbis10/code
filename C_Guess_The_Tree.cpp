#include <bits/stdc++.h>
using namespace std;
#define int long long


pair<int, int> findBinarySearch(int start, int end, int targetNode) {
    int left = start;
    int right = targetNode;
    while (true) {
        cout << "? " << left << " " << right << endl;
        cout.flush();
        int response;
        cin >> response;
        if (response == left) {
            return make_pair(left, right);
        }
        right = response;
    }
}

void solveTestCase() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        cout << "? " << i << " " << n << endl;
        cout.flush();
        int targetNode;
        cin >> targetNode;
        if (targetNode == i) {
            edges.push_back(make_pair(i, n));
            continue;
        }
        pair<int, int> edge = findBinarySearch(i, n, targetNode);
        edges.push_back(edge);
    }
    cout << "! ";
    for (auto &edge : edges) {
        cout << edge.first << " " << edge.second << " ";
    }
    cout << endl;
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solveTestCase();
    }
}
