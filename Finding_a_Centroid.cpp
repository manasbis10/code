#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

map<int, vector<int>> adj; // Adjacency list to store the tree
int n; // Number of nodes in the tree

// Function to calculate the subtree sizes
void solve(vector<int>& sub, int node, int parent) {
    sub[node] = 1; // Initialize the current node's subtree size to 1 (itself)
    for (auto nbr : adj[node]) {
        if (nbr != parent) { // If the neighbor is not the parent, it's part of the subtree
            solve(sub, nbr, node); // Recursive call to process the subtree of the neighbor
            sub[node] += sub[nbr]; // Add the size of the neighbor's subtree to the current node's subtree size
        }
    }
}

// Function to find the centroid of the tree
int centroid(int node, int parent, vector<int>& sub) {
    for (auto nbr : adj[node]) {
        if (nbr != parent && sub[nbr] > n / 2) { // If any subtree of a child has more than n/2 nodes,
            return centroid(nbr, node, sub); // then the centroid must be in that subtree.
        }
    }
    return node; // If no such child is found, then the current node is the centroid.
}

int main() {
    cin >> n;

    // Since nodes are usually 1-indexed in problems, adjust the loop to start from 0
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; // Read the edge between nodes u and v
        adj[u].push_back(v); // Add v to the list of u's neighbors
        adj[v].push_back(u); // Add u to the list of v's neighbors
    }

    vector<int> sub(n + 1); // Vector to store subtree sizes, 1-indexed

    solve(sub, 1, -1); // Calculate subtree sizes starting from node 1, assuming no parent for the root

    // Uncomment below if you want to print subtree sizes
    // for(int i = 1; i <= n; i++) cout << sub[i] << " ";
    // cout << endl;

    // Find and print the centroid
    cout << centroid(1, -1, sub) << endl;

    return 0;
}
