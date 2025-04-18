#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    string t;
    cin >> t;
    int hh = stoi(t.substr(0, 2));
    int mm = stoi(t.substr(3, 2));
    string ans;
    
    if (hh == 0) {
        cout << "12:" << t.substr(3, 2) << " AM" << endl;
        return;
    }
    if (hh < 12) {
        // Fixed formatting for hours less than 10
        if (hh < 10) {
            ans = "0" + to_string(hh);
        } else {
            ans = to_string(hh);
        }
        cout << ans << ":" << t.substr(3, 2) << " AM" << endl;
        return;
    }
    if (hh == 12) {
        cout << "12:" << t.substr(3, 2) << " PM" << endl;
        return;
    }
    if (hh > 12) {
        // Fixed formatting for hours between 1 PM and 9 PM to include leading zero
        int convertedHour = hh - 12;
        if (convertedHour < 10) {
            ans = "0" + to_string(convertedHour);
        } else {
            ans = to_string(convertedHour);
        }
        cout << ans << ":" << t.substr(3, 2) << " PM" << endl;
        return;
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
