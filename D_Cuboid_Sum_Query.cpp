#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    int size = pow(3, n);

    // Initialize the 3D matrix
    vector<vector<vector<int>>> arr(size, vector<vector<int>>(size, vector<int>(size, 0)));
    
    // Initialize a 3D vector to store prefix sums
    vector<vector<vector<int>>> prefix(size, vector<vector<int>>(size, vector<int>(size, 0)));

    // Read input and compute prefix sums for each 2D matrix in the 3D matrix
    for(int z = 0; z < size; z++) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                cin >> arr[z][i][j];
                
                // Compute the prefix sum for the current 2D slice at depth z
                prefix[z][i][j] = arr[z][i][j];
                if (i > 0) prefix[z][i][j] += prefix[z][i-1][j];
                if (j > 0) prefix[z][i][j] += prefix[z][i][j-1];
                if (i > 0 && j > 0) prefix[z][i][j] -= prefix[z][i-1][j-1];
            }
        }
    }

    int Q;
    cin >> Q;
    
    // Answer each query
    while(Q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        Lx--; Rx--; Ly--; Ry--; Lz--; Rz--; // Convert to 0-based indexing

        int result = 0;

        // Ensure indices are within bounds
        assert(Lx >= 0 && Rx < size);
        assert(Ly >= 0 && Ry < size);
        assert(Lz >= 0 && Rz < size);

        for(int x = Lx; x <= Rx; x++) {
            int sum = prefix[x][Ry][Rz];

            if (Ly > 0) sum -= prefix[x][Ly-1][Rz];
            if (Lz > 0) sum -= prefix[x][Ry][Lz-1];
            if (Ly > 0 && Lz > 0) sum += prefix[x][Ly-1][Lz-1];
            
            result += sum;
        }

        cout << result << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
