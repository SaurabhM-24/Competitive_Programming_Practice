#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> representatives;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i, adj, visited);
        }
    }

    int num_edges_to_add = representatives.size() - 1;
    if (num_edges_to_add == 0) {
        cout << "The graph is already connected.\n";
    } else {
        cout << num_edges_to_add << "\n";
        for (int i = 1; i < representatives.size(); ++i) {
            cout << representatives[i - 1] << " " << representatives[i] << "\n";
        }
    }
    return 0;
}
